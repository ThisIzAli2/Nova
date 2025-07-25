/**
 * @author Ali Mirmohammad
 * @file directgui.h
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
#ifndef __NovanixLIB__GUI__DIRECTGUI_H
#define __NovanixLIB__GUI__DIRECTGUI_H

#include <types.h>
#include <gui/canvas.h>

namespace Novanix
{
    class DirectGUI
    {
    public:
        static bool RequestFramebuffer();
        static Canvas* GetCanvas();

        static void SetPixel(int x, int y, uint32_t color);
        static uint32_t GetPixel(int x, int y);

        static void Clear();
        static void Clear(uint32_t color);
        static void DrawHorizontalLine(uint32_t color, int dx, int x1, int y1);
        static void DrawVerticalLine(uint32_t color, int dx, int x1, int y1);
        static void DrawLine(uint32_t color, int x1, int y1, int x2, int y2);
        static void DrawDiagonalLine(uint32_t color, int dx, int dy, int x1, int y1);
        static void DrawRect(uint32_t color, int x, int y, int width, int height);
        static void DrawFillRect(uint32_t color, int x_start, int y_start, int width, int height);
        static void DrawCircle(uint32_t color, int x_center, int y_center, int radius);
        static void DrawFillCircle(uint32_t color, int x_center, int y_center, int radius);
        static void DrawEllipse(uint32_t color, int x_center, int y_center, int x_radius, int y_radius);

        static void DrawChar(char character, int x, int y, uint32_t color);
        static void DrawString(char* string, int x, int y, uint32_t color);
    };
}

#endif