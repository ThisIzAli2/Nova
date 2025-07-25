/**
 * @author Ali Mirmohammad
 * @file new.h
 * @credits remco123
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
#ifndef __Novanix__NEW_H
#define __Novanix__NEW_H

#include <stddef.h>
#include <heap.h>

using namespace Novanix;
 
void *operator new(size_t size)
{
    return UserHeap::Malloc(size);
}
 
void *operator new[](size_t size)
{
    return UserHeap::Malloc(size);
}

void* operator new(size_t size, void* ptr)
{
    return ptr;
}

void* operator new[](size_t size, void* ptr)
{
    return ptr;
}
 
void operator delete(void *p)
{
    UserHeap::Free(p);
}
 
void operator delete[](void *p)
{
    UserHeap::Free(p);
}

void operator delete(void* ptr, size_t size)
{
    UserHeap::Free(ptr);
}
void operator delete[](void* ptr, size_t size)
{
    UserHeap::Free(ptr);
}

#endif