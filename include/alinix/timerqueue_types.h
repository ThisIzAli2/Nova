/**
 * @author Ali Mirmohammad
 * @file timerqueue_types.h
 ** This file is part of AliNix.

**AliNix is free software: you can redistribute it and/or modify
**it under the terms of the GNU Affero General Public License as published by
**the Free Software Foundation, either version 3 of the License, or
**(at your option) any later version.

**AliNix is distributed in the hope that it will be useful,
**but WITHOUT ANY WARRANTY; without even the implied warranty of
**MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
**GNU Affero General Public License for more details.

**You should have received a copy of the GNU Affero General Public License
**along with AliNix. If not, see <https://www.gnu.org/licenses/>.
*/

/**
 * @abstraction:
 * 	- Kernel timer header types util.
*/

#ifndef __ALINIX_KERNEL_TIMER_QUEUE_TYPES_H
#define __ALINIX_KERNEL_TIMER_QUEUE_TYPES_H

#include <alinix/types.h>
#include <alinix/rbtree_types.h>

struct timerqueue_node {
	struct rb_node node;
	ktime_t expires;
};



#endif // __ALINIX_KERNEL_TIMER_QUEUE_TYPES_H