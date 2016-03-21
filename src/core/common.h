/*
 * Copyright (c) 2016 WinT 3794 <http://wint3794.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _KZ_2016_COMMON_H
#define _KZ_2016_COMMON_H

#include <WPILib.h>

inline float REMOVE_DEADBAND (float input) {
    if (std::abs (input) <= 0.1)
        return 0;

    return input;
}

namespace RobotHardware {
enum PWMs {
    kHands        = 0,
    kShooter      = 1,
    kLifter       = 2,
    kDriveLeft    = 3,
    kDriveRight   = 4,
    kHangerBase   = 5,
    kHangerAngleA = 6,
    kHangerAngleB = 7,
};
}

namespace Joysticks {
enum Axes {
    kAxisLT       = 2,
    kAxisRT       = 3,
    kAxisLeftX    = 0,
    kAxisLeftY    = 1,
    kAxisRightX   = 4,
    kAxisRightY   = 5,
};

enum Buttons {
    kButtonA      = 1,
    kButtonB      = 2,
    kButtonX      = 3,
    kButtonY      = 4,
    kButtonLB     = 5,
    kButtonRB     = 6,
    kButtonHome   = 7,
    kButtonStart  = 8,
};
}

#endif
