/**
 * @author Ali Mirmohammad
 * @file window.h
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
#ifndef __Novanix__WINDOW_H
#define __Novanix__WINDOW_H

#include <gui/widgets/control.h>
#include <gui/widgets/button.h>
#include <gui/context.h>
#include <gui/property.h>

namespace Novanix
{
    class Button;
    
    class Window : public Control
    {
    public:
        GUIProperty<uint32_t> titleBarColor = GUIProperty<uint32_t>(this, 0xFF1E9AFF);
        GUIProperty<uint16_t> titleBarHeight = GUIProperty<uint16_t>(this, 30);
    private:
        // Is the mouse down on the title bar?
        GUIProperty<bool> titleBarMouseDown = GUIProperty<bool>(this, false);

        // Remember where the mouse was held down for a smooth window drag
        int mouseDownX = 0;
        int mouseDownY = 0;

        // Window Control Buttons
        Button* closeButton = 0;

        // Create the close button for this window
        void CreateButtons();
    public:
        GUIProperty<char*> titleString = GUIProperty<char*>(this, 0);

        /**
         * In which context are we located?
        */
        Context* contextBase = 0;

        /**
         * Create a new window with a context as base
        */
        Window(Context* base);

        /**
         * Create a new window that request a context for itself to use
        */
        Window(int width, int height, int x, int y);
        
        /**
         * Close this window, this can cause the application to exit
        */
        void Close(void* sender, MouseButtonArgs arg);
        /**
         * Close this window, this can cause the application to exit
        */
        void Close();

        /**
         * Draw this window to a canvas
         * 
         * x_abs/y_abs: the coördinate of this window in absolute related to the canvas
        */
        void DrawTo(Canvas* context, int x_abs, int y_abs) override;
    friend class Context;
    protected:
        /**
         * Called when mouse is down on window
        */
        void OnMouseDown(int x_abs, int y_abs, uint8_t button) override;
        /**
         * Called when mouse is up on window
        */
        void OnMouseUp(int x_abs, int y_abs, uint8_t button) override;
        /**
         * Called when mouse is moved on window
        */
        void OnMouseMove(int prevX_abs, int prevY_abs, int newX_abs, int newY_abs) override;
        /**
         * Called when Window is resized
        */
        void OnResize(Rectangle old) override;
        /**
         * Called when key is held down
        */
        void OnKeyDown(uint8_t key, KEYPACKET_FLAGS modifiers) override;
        /**
         * Called when there is a scroll event on window
        */
        void OnScroll(int32_t deltaZ, int x_abs, int y_abs) override;
    };
}

#endif