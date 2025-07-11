/**
 * @author Ali Mirmohammad
 * @file port.h
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
#ifndef __Novanix__CORE__PORT_H
#define __Novanix__CORE__PORT_H

#include <common/types.h>

namespace Novanix
{
    namespace core
    {
        #define insl(port, buffer, count) asm volatile("cld; rep; insl" :: "D" (buffer), "d" (port), "c" (count))

        inline static unsigned char inportb (unsigned short _port)
        {
            unsigned char rv;
            __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
            return rv;
        }

        inline static void outportb (unsigned short _port, unsigned char _data)
        {
            __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
        }

        inline static void outl(common::uint16_t port, common::uint32_t value) {
        __asm__ volatile (
            "outl %0, %1"
            :
            : "a"(value), "Nd"(port)
        );
        }

        inline static unsigned short inportw(unsigned short _port)
        {
            unsigned short rv;
            __asm__ __volatile__ ("inw %1, %0" : "=a" (rv) : "dN" (_port));
            return rv;
        }

        inline static void outportw(unsigned short _port, unsigned short _data)
        {
            __asm__ __volatile__ ("outw %1, %0" : : "dN" (_port), "a" (_data));
        }
        inline static unsigned int inportl(unsigned short _port)
        {
            unsigned int val;
            __asm__ __volatile__ ("inl %%dx, %%eax" : "=a" (val) : "d" (_port));
            return( val );
        }
        inline static void outportl(unsigned short _port, unsigned int _data)
        {
            __asm__ __volatile__ ("outl %%eax, %%dx" : : "d" (_port), "a" (_data));
        }

        inline static void inportsm(unsigned short port, unsigned char * data, unsigned long size)
        {
            asm volatile ("rep insw" : "+D" (data), "+c" (size) : "d" (port) : "memory");
        }

        inline static void outportsm(unsigned short port, unsigned char * data, unsigned long size) {
	        asm volatile ("rep outsw" : "+S" (data), "+c" (size) : "d" (port));
        }

        inline static void writeMemReg(const common::uint32_t addr, const common::uint32_t val) {
            *(volatile common::uint32_t*)addr = val;
        }

        inline static common::uint32_t readMemReg(const common::uint32_t addr) {
            return *(volatile common::uint32_t*)addr;
        }

    }
}

#ifndef outb
#define outb Novanix::core::outportb
#endif 

#ifndef inb
#define inb Novanix::core::inportb
#endif


#endif