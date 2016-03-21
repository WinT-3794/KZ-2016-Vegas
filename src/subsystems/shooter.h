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

class Shooter {
  public:
    static Shooter* getInstance() {
        static Shooter shooter;
        return &shooter;
    }

    void move (float value) {
        m_motor->Set (REMOVE_DEADBAND (value));
    }

    void move (Joystick* joystick) {
        float speed = 0;
        float lb = joystick->GetRawAxis (Joysticks::kAxisLB);
        float rb = joystick->GetRawAxis (Joysticks::kAxisRB);

        if (lb > rb)
            speed = lb;

        else if (lb < rb)
            speed = rb * -1;

        move (speed);
    }

  protected:
    Shooter() {
        m_motor = new VictorSP (RobotHardware::kShooter);
    }

  private:
    VictorSP* m_motor;
};