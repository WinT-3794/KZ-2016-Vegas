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

#pragma once
#include "core/common.h"

class Drive {
  public:
    static Drive* getInstance() {
        static Drive drive;
        return &drive;
    }

    void move (float x, float y, float limit, bool inverted) {
        limit = std::abs (limit);

        x *= limit;
        y *= limit;
        y *= inverted ? -1 : 1;

        m_drive->ArcadeDrive (REMOVE_DEADBAND (y),
                              REMOVE_DEADBAND (x),
                              true);
    }

    void move (Joystick* joystick) {
        float l = joystick->GetRawAxis (Joysticks::kAxisRT);
        float x = joystick->GetRawAxis (Joysticks::kAxisLeftX);
        float y = joystick->GetRawAxis (Joysticks::kAxisLeftY);
        move (x, y, 1.0 - l, joystick->GetRawButton (Joysticks::kButtonA));
    }

  protected:
    Drive() {
        m_drive = new RobotDrive (RobotHardware::kDriveLeft,
                                  RobotHardware::kDriveRight);
    }

  private:
    RobotDrive* m_drive;
};
