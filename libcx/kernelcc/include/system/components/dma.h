/**
 * @author Ali Mirmohammad
 * @file dma.h
 * @credits Remco123
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
#ifndef __Novanix__SYSTEM__COMPONENTS__DMA_H
#define __Novanix__SYSTEM__COMPONENTS__DMA_H

// Main source: http://www.brokenthorn.com/Resources/OSDev21.html

#include <system/components/systemcomponent.h>
#include <common/types.h>

namespace Novanix
{
    namespace system
    {
        // Slave Registers
        enum DMA0_IO {
            DMA0_STATUS_REG = 0x08,
            DMA0_COMMAND_REG = 0x08,
            DMA0_REQUEST_REG = 0x09,
            DMA0_CHANMASK_REG = 0x0a,
            DMA0_MODE_REG = 0x0b,
            DMA0_CLEARBYTE_FLIPFLOP_REG = 0x0c,
            DMA0_TEMP_REG = 0x0d,
            DMA0_MASTER_CLEAR_REG = 0x0d,
            DMA0_CLEAR_MASK_REG = 0x0e,
            DMA0_MASK_REG = 0x0f
        };

        // Master Registers
        enum DMA1_IO {
            DMA1_STATUS_REG = 0xd0,
            DMA1_COMMAND_REG = 0xd0,
            DMA1_REQUEST_REG = 0xd2,
            DMA1_CHANMASK_REG = 0xd4,
            DMA1_MODE_REG = 0xd6,
            DMA1_CLEARBYTE_FLIPFLOP_REG = 0xd8,
            DMA1_INTER_REG = 0xda,
            DMA1_UNMASK_ALL_REG = 0xdc,
            DMA1_MASK_REG = 0xde
        };

        // Slave Channel Registers
        enum DMA0_CHANNEL_IO {
            DMA0_CHAN0_ADDR_REG = 0,
            DMA0_CHAN0_COUNT_REG = 1,
            DMA0_CHAN1_ADDR_REG = 2,
            DMA0_CHAN1_COUNT_REG = 3,
            DMA0_CHAN2_ADDR_REG = 4,
            DMA0_CHAN2_COUNT_REG = 5,
            DMA0_CHAN3_ADDR_REG = 6,
            DMA0_CHAN3_COUNT_REG = 7,
        };

        // Master Channel Registers
        enum DMA1_CHANNEL_IO {
            DMA1_CHAN4_ADDR_REG = 0xc0,
            DMA1_CHAN4_COUNT_REG = 0xc2,
            DMA1_CHAN5_ADDR_REG = 0xc4,
            DMA1_CHAN5_COUNT_REG = 0xc6,
            DMA1_CHAN6_ADDR_REG = 0xc8,
            DMA1_CHAN6_COUNT_REG = 0xca,
            DMA1_CHAN7_ADDR_REG = 0xcc,
            DMA1_CHAN7_COUNT_REG = 0xce,
        };

        // Extended Page Address Registers
        enum DMA0_PAGE_REG {

            DMA_PAGE_EXTRA0 = 0x80,
            DMA_PAGE_CHAN2_ADDRBYTE2 = 0x81,
            DMA_PAGE_CHAN3_ADDRBYTE2 = 0x82,
            DMA_PAGE_CHAN1_ADDRBYTE2 = 0x83,
            DMA_PAGE_EXTRA1 = 0x84,
            DMA_PAGE_EXTRA2 = 0x85,
            DMA_PAGE_EXTRA3 = 0x86,
            DMA_PAGE_CHAN6_ADDRBYTE2 = 0x87,
            DMA_PAGE_CHAN7_ADDRBYTE2 = 0x88,
            DMA_PAGE_CHAN5_ADDRBYTE2 = 0x89,
            DMA_PAGE_EXTRA4 = 0x8c,
            DMA_PAGE_EXTRA5 = 0x8d,
            DMA_PAGE_EXTRA6 = 0x8e,
            DMA_PAGE_DRAM_REFRESH = 0x8f
        };

        enum DMA_CMD_REG_MASK {

            DMA_CMD_MASK_MEMTOMEM = 1,
            DMA_CMD_MASK_CHAN0ADDRHOLD = 2,
            DMA_CMD_MASK_ENABLE = 4,
            DMA_CMD_MASK_TIMING = 8,
            DMA_CMD_MASK_PRIORITY = 0x10,
            DMA_CMD_MASK_WRITESEL = 0x20,
            DMA_CMD_MASK_DREQ = 0x40,
            DMA_CMD_MASK_DACK = 0x80
        };

        enum DMA_MODE_REG_MASK {

            DMA_MODE_MASK_SEL = 3,

            DMA_MODE_MASK_TRA = 0xc,
            DMA_MODE_SELF_TEST = 0,
            DMA_MODE_READ_TRANSFER =4,
            DMA_MODE_WRITE_TRANSFER = 8,

            DMA_MODE_MASK_AUTO = 0x10,
            DMA_MODE_MASK_IDEC = 0x20,

            DMA_MODE_MASK = 0xc0,
            DMA_MODE_TRANSFER_ON_DEMAND= 0,
            DMA_MODE_TRANSFER_SINGLE = 0x40,
            DMA_MODE_TRANSFER_BLOCK = 0x80,
            DMA_MODE_TRANSFER_CASCADE = 0xC0
        };

        // Controls the DMA Controller chip
        // Only used for legacy floppy disks
        class DMAController : public SystemComponent
        {
        public:
            void SetChannelAddress(common::uint8_t channel, common::uint8_t low, common::uint8_t high);
            void SetChannelCounter(common::uint8_t channel, common::uint8_t low, common::uint8_t high);
            void SetExternalPageRegister(common::uint8_t reg, common::uint8_t val);
            void SetChannelMode(common::uint8_t channel, common::uint8_t mode);
            void ChannelPrepareRead(common::uint8_t channel);
            void ChannelPrepareWrite(common::uint8_t channel);
            void MaskChannel(common::uint8_t channel);
            void UnmaskChannel(common::uint8_t channel);
            void ResetFlipFlop(int dma);
            void Reset(int dma);
            void UnmaskAll(int dma);
        public:
            DMAController();
        };
    }
}

#endif