/**
 * @author Ali Mirmohammad
 * @file canvas.h
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
#ifndef __Novanix__GUI__CANVAS_H
#define __Novanix__GUI__CANVAS_H

#include <types.h>
#include <gui/fonts/font.h>

namespace Novanix
{
    class Canvas
    {
    private:
        void DrawCircleHelper(int x, int y, int radius, uint32_t corner, uint32_t color);
        void FillCircleHelper(int x, int y, int radius, uint32_t corner, int delta, uint32_t color);
    public:
        void* bufferPointer;
        int Width;
        int Height;

        Canvas(void* buffer, int w, int h);

        void SetPixel(int x, int y, uint32_t color);
        uint32_t GetPixel(int x, int y);

        void Clear();
        void Clear(uint32_t color);
        void DrawHorizontalLine(uint32_t color, int dx, int x1, int y1);
        void DrawVerticalLine(uint32_t color, int dx, int x1, int y1);
        void DrawLine(uint32_t color, int x1, int y1, int x2, int y2);
        void DrawDiagonalLine(uint32_t color, int dx, int dy, int x1, int y1);
        void DrawRect(uint32_t color, int x, int y, int width, int height);
        void DrawRoundedRect(uint32_t color, int x, int y, int width, int height, int radius);
        void DrawFillRoundedRect(uint32_t color, int x, int y, int width, int height, int radius);
        void DrawFillRect(uint32_t color, int x_start, int y_start, int width, int height);
        void DrawCircle(uint32_t color, int x_center, int y_center, int radius);
        void DrawFillCircle(uint32_t color, int x_center, int y_center, int radius);
        void DrawEllipse(uint32_t color, int x_center, int y_center, int x_radius, int y_radius);

        void DrawString(Font* font, char* string, int x, int y, uint32_t color);
    };
}

#endif