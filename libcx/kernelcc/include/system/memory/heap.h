/**
 * @author Ali Mirmohammad
 * @file heap.h
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
#ifndef __Novanix__SYSTEM__HEAP_H
#define __Novanix__SYSTEM__HEAP_H

#include <core/virtualmemory.h>
#include <system/tasking/lock.h>

namespace Novanix
{
    namespace system
    {
        #define KERNEL_HEAP_START (KERNEL_VIRT_ADDR + 4_MB)
        #define KERNEL_HEAP_SIZE 16_MB

        // Only split a memory block when we can use it to store this amount of data in it
        #define MINIMAL_SPLIT_SIZE 4
        
        // Magic number used for memory headers
        #define MEMORY_HEADER_MAGIC 1234567890

        #ifndef align_up
        #define align_up(num, align) \
            (((num) + ((align) - 1)) & ~((align) - 1))
        #endif

        struct MemoryHeader
        {
            common::uint32_t magic;

            MemoryHeader* next;
            MemoryHeader* prev;
            common::uint32_t allocated;
            common::uint32_t size;
        } __attribute__((packed));

        class KernelHeap
        {
        private:
            static common::uint32_t startAddress;
            static common::uint32_t endAddress;

            static MemoryHeader* firstHeader;

            static void* InternalAllocate(common::uint32_t size);
            static MemoryHeader* FirstFree(common::uint32_t size);

            static MutexLock heapMutex;
        public:
            static void Initialize(common::uint32_t start, common::uint32_t end);

            static void* malloc(common::uint32_t size, common::uint32_t* physReturn = 0);
            static void free(void* ptr);

            static void* alignedMalloc(common::uint32_t size, common::uint32_t align, common::uint32_t* physReturn = 0);
            static void allignedFree(void* ptr);

            static bool CheckForErrors();
            static common::uint32_t UsedMemory();
        };
    }
}


#endif