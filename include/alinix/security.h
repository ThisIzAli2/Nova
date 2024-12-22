/**
 * @author Ali Mirmohammad
 * @file security.h
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
 * 	- Kernel security header file implementation and provides util for the kernel security stuff.
*/
#ifndef __ALINIX_KERNEL_SECURITY_H
#define __ALINIX_KERNEL_SECURITY_H

/**
 * @brief Reason of the kernel lock down.
 * @brief This enum should be used whenever the kernel is being lock downed.
*/

enum lockdown_reason {
	LOCKDOWN_NONE,
	LOCKDOWN_MODULE_SIGNATURE,
	LOCKDOWN_DEV_MEM,
	LOCKDOWN_EFI_TEST,
	LOCKDOWN_KEXEC,
	LOCKDOWN_HIBERNATION,
	LOCKDOWN_PCI_ACCESS,
	LOCKDOWN_IOPORT,
	LOCKDOWN_MSR,
	LOCKDOWN_ACPI_TABLES,
	LOCKDOWN_DEVICE_TREE,
	LOCKDOWN_PCMCIA_CIS,
	LOCKDOWN_TIOCSSERIAL,
	LOCKDOWN_MODULE_PARAMETERS,
	LOCKDOWN_MMIOTRACE,
	LOCKDOWN_DEBUGFS,
	LOCKDOWN_XMON_WR,
	LOCKDOWN_BPF_WRITE_USER,
	LOCKDOWN_DBG_WRITE_KERNEL,
	LOCKDOWN_RTAS_ERROR_INJECTION,
	LOCKDOWN_INTEGRITY_MAX,
	LOCKDOWN_KCORE,
	LOCKDOWN_KPROBES,
	LOCKDOWN_BPF_READ_KERNEL,
	LOCKDOWN_DBG_READ_KERNEL,
	LOCKDOWN_PERF,
	LOCKDOWN_TRACEFS,
	LOCKDOWN_XMON_RW,
	LOCKDOWN_XFRM_SECRET,
	LOCKDOWN_CONFIDENTIALITY_MAX,
	MEMORY_CORRUPTION
};

/**
 * @brief Used for when memory corruption occur.
*/
void kernelMemoryCorruptionLockDown();

#endif /*__ALINIX_KERNEL_SECURITY_H*/