/**
 * @author Ali Mirmohammad
 * @file memaccess.h
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
#ifndef __NOVANIX_KERNEL_MEM_ACCESS_H
#define __NOVANIX_KERNEL_MEM_ACCESS_H


/**
 * This file is for protecting the memory from being access arbitrary.
 */

#include <common/init.hpp>
#include <security/generic.h>


#include <common/init.hpp>

VOID reset_super_access();

#endif /*__NOVANIX_KERNEL_MEM_ACCESS_H*/