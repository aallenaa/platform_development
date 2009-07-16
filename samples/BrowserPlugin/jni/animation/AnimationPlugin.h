/*
 * Copyright 2008, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "PluginObject.h"

#ifndef pluginGraphics__DEFINED
#define pluginGraphics__DEFINED

class BallAnimation : public SubPlugin {
public:
    BallAnimation(NPP inst);
    virtual ~BallAnimation();
    virtual bool supportsDrawingModel(ANPDrawingModel);
    virtual int16 handleEvent(const ANPEvent* evt);
private:
    void draw(ANPCanvas*);
    void drawPlugin(const ANPBitmap& bitmap, const ANPRectI& clip);
    void centerPluginOnScreen();

    float m_x;
    float m_y;
    float m_dx;
    float m_dy;

    int32_t mUnichar;

    ANPRectF    m_oval;
    ANPPaint*   m_paint;

    static const float SCALE = 0.1;

    int m_scrollX;
    int m_scrollY;
    int m_screenH;
    int m_screenW;
    float m_zoom;
};

uint32_t getMSecs();

#endif // pluginGraphics__DEFINED
