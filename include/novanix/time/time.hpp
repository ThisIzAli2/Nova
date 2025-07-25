/**
 * @author Ali Mirmohammad
 * @file time.hpp
 ** This file is part of Novanix.

**Novanix is free software: you can redistribute it and/or modify
**it under the terms of the GNU Affero General Public License as published by
**the Free Software Foundation, either version 3 of the License, or
**(at your option) any later version.

**Novanix is distributed in the hope that it will be useful,
**but WITHOUT ANY WARRANTY; without even the implied warranty of
**MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
**GNU Affero General Public License for more details.

**You should have received a copy of the GNU Affero General Public License
**along with Novanix. If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef __NOVANIX_KERNEL_TIME_HPP
#define __NOVANIX_KERNEL_TIME_HPP


#include <common/types.h>
#include <typing.hpp>
#include <system/log.h>
#include <novanix/ops.h>
#include <typing.hpp>
#include <core/port.h>

// https://wiki.osdev.org/RTC

static inline Novanix::common::uint64_t read_tsc(VOID) {
    Novanix::common::uint32_t low, high;
    __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
    return ((Novanix::common::uint64_t)high << 32) | low;
}

VOID inline display_time(VOID) {
    Novanix::common::uint64_t tsc = read_tsc();
    
    Novanix::common::uint64_t time_in_seconds = __udivdi3(1000000000,tsc);  // Assuming 1 GHz clock for simplicity
    
    // Convert time to a readable format
    Novanix::system::printk(Novanix::system::VGA_COLOR_WHITE,"Time since boot: %llu seconds\n", 1,time_in_seconds);
}

#define CURRENT_YEAR        2025                          // Change this each year!

static int century_register = 0x00;                                // Set by ACPI table parsing code if possible

static unsigned char second;
static unsigned char minute;
static unsigned char hour;
static unsigned char day;
static unsigned char month;
static unsigned int year;


enum {
      cmos_address = 0x70,
      cmos_data    = 0x71
};

int inline get_update_in_progress_flag() {
      Novanix::core::outportb(cmos_address, 0x0A);
      return (Novanix::core::inportb(cmos_data) & 0x80);
}

unsigned char inline get_RTC_register(int reg) {
      Novanix::core::outportb(cmos_address, reg);
      return Novanix::core::inportb(cmos_data);
}

void inline read_rtc() {
      unsigned char century;
      unsigned char last_second;
      unsigned char last_minute;
      unsigned char last_hour;
      unsigned char last_day;
      unsigned char last_month;
      unsigned char last_year;
      unsigned char last_century;
      unsigned char registerB;

      // Note: This uses the "read registers until you get the same values twice in a row" technique
      //       to avoid getting dodgy/inconsistent values due to RTC updates

      while (get_update_in_progress_flag());                // Make sure an update isn't in progress
      second = get_RTC_register(0x00);
      minute = get_RTC_register(0x02);
      hour = get_RTC_register(0x04);
      day = get_RTC_register(0x07);
      month = get_RTC_register(0x08);
      year = get_RTC_register(0x09);
      if(century_register != 0) {
            century = get_RTC_register(century_register);
      }

      do {
            last_second = second;
            last_minute = minute;
            last_hour = hour;
            last_day = day;
            last_month = month;
            last_year = year;
            last_century = century;

            while (get_update_in_progress_flag());           // Make sure an update isn't in progress
            second = get_RTC_register(0x00);
            minute = get_RTC_register(0x02);
            hour = get_RTC_register(0x04);
            day = get_RTC_register(0x07);
            month = get_RTC_register(0x08);
            year = get_RTC_register(0x09);
            if(century_register != 0) {
                  century = get_RTC_register(century_register);
            }
      } while( (last_second != second) || (last_minute != minute) || (last_hour != hour) ||
               (last_day != day) || (last_month != month) || (last_year != year) ||
               (last_century != century) );

      registerB = get_RTC_register(0x0B);

      // Convert BCD to binary values if necessary

      if (!(registerB & 0x04)) {
            second = (second & 0x0F) + ((second / 16) * 10);
            minute = (minute & 0x0F) + ((minute / 16) * 10);
            hour = ( (hour & 0x0F) + (((hour & 0x70) / 16) * 10) ) | (hour & 0x80);
            day = (day & 0x0F) + ((day / 16) * 10);
            month = (month & 0x0F) + ((month / 16) * 10);
            year = (year & 0x0F) + ((year / 16) * 10);
            if(century_register != 0) {
                  century = (century & 0x0F) + ((century / 16) * 10);
            }
      }

      // Convert 12 hour clock to 24 hour clock if necessary

      if (!(registerB & 0x02) && (hour & 0x80)) {
            hour = ((hour & 0x7F) + 12) % 24;
      }

      // Calculate the full (4-digit) year

      if(century_register != 0) {
            year += century * 100;
      } else {
            year += (CURRENT_YEAR / 100) * 100;
            if(year < CURRENT_YEAR) year += 100;
      }
}

#endif /*__NOVANIX_KERNEL_TIME_HPP*/