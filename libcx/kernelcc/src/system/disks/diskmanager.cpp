/**
 * @author Ali Mirmohammad
 * @file diskmanager.cpp
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
#include <system/disks/diskmanager.h>

#include <system/drivers/disk/ide.h>
#include <system/system.h>

using namespace Novanix;
using namespace Novanix::common;
using namespace Novanix::system;
using namespace Novanix::system::drivers;

// VM86 Function to get info about a specific disk device
// We must do it this way because the DS:SI gets used by the CallInterrupt() method
extern "C" uint8_t diskInfo;

DiskManager::DiskManager()
{ 
    allDisks.Clear();
}

char DiskManager::ReadSector(uint16_t drive, uint32_t lba, uint8_t* buf)
{
    if(drive < allDisks.size())
        return allDisks[drive]->ReadSector(lba, buf);
    return 1;
}

char DiskManager::WriteSector(uint16_t drive, uint32_t lba, uint8_t* buf)
{
    if(drive < allDisks.size())
        return allDisks[drive]->WriteSector(lba, buf);
    return 1;
}

void DiskManager::AddDisk(Disk* disk)
{
    //Add Disk to list of all disk
    allDisks.push_back(disk);
    //Try to detect filesystems present on disk
    PartitionManager::DetectAndLoadFilesystem(disk);
}
void DiskManager::RemoveDisk(Disk* disk)
{
    allDisks.Remove(disk); //Remove from list
    System::vfs->UnmountByDisk(disk); //And unmount all filesystems using that disk
}

BiosDriveParameters* DiskManager::GetDriveInfoBios(uint8_t drive)
{
    System::vm86Manager->ExecuteCode((uint32_t)&diskInfo, drive);
    return (BiosDriveParameters*)0x7000;
}