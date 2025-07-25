/**
 * @author Ali Mirmohammad
 * @file bmpformat.cpp
 * Credits Remco123
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
#include <imaging/bmpformat.h>
#include <log.h>
#include <string.h>
#include <math.h>
#include <vfs.h>

using namespace Novanix;
using namespace Novanix::Imaging;

Image* Imaging::ConvertBMP(const char* filepath)
{
    Print("[BMP] Converting image file %s\n", filepath);

    if(FileExists((char*)filepath))
    {
        uint32_t fileSize = GetFileSize((char*)filepath);
        if(fileSize != (uint32_t)-1)
        {
            uint8_t* fileBuf = new uint8_t[fileSize];
            ReadFile((char*)filepath, fileBuf);
            
            Image* result = ConvertBMPRaw(fileBuf);
            delete fileBuf;
            return result;
        }
    }

    Print("[BMP] Error processing file %s\n", filepath);
    return 0;
}

Image* Imaging::ConvertBMPRaw(const uint8_t* rawData)
{
    const uint8_t* realBuffPtr = rawData;

    BMPFileHeader* fileHeader = (BMPFileHeader*)rawData;
    if(fileHeader->fileType != 0x4D42)
        return 0;
    
    rawData += sizeof(BMPFileHeader);
    BMPInfoHeader* infoHeader = (BMPInfoHeader*)rawData;

    if(infoHeader->BitCount != 24 || infoHeader->Compression != 0) {
        Log(Error, "[BMP] Image not supported");
        return 0;
    }

    // Jump to begin of pixel data
    rawData = (realBuffPtr + fileHeader->dataOffset);

    // Create result image
    Image* result = new Image(infoHeader->Width, infoHeader->Height);
    uint32_t* resultBuffer = result->GetBufferPtr();

    // Copy data to result image
    int align = (infoHeader->Width * 3) % 4;
    if (align != 0)
        align = 4 - align; 

    int offset, rowOffset;
    for (int y = 0; y < infoHeader->Height; y++) {
        rowOffset = (infoHeader->Height - y - 1) * (infoHeader->Width * 3 + align);
        for (int x = 0; x < infoHeader->Width; x++) {
            offset = rowOffset + x * 3;
            
            uint32_t b = rawData[offset + 0];
            uint32_t g = rawData[offset + 1];
            uint32_t r = rawData[offset + 2];

            resultBuffer[y * infoHeader->Width + x] = 0xFF000000 | r << 16 | g << 8  | b;
        }
    }

    return result;
}