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