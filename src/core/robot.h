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

#include "subsystems/hands.h"
#include "subsystems/drive.h"
#include "subsystems/shooter.h"

class Robot : public IterativeRobot {
  public:
    void RobotInit() {
        m_hands   = Hands::getInstance();
        m_drive   = Drive::getInstance();
        m_shooter = Shooter::getInstance();

        joystick0 = new Joystick (0);
        joystick1 = new Joystick (1);
    }

    void TeleopInit() {

    }

    void DisabledInit() {

    }

    void AutonomousInit() {

    }

    void TeleopPeriodic() {
        m_drive->move   (joystick0);
        m_hands->move   (joystick1);
        m_shooter->move (joystick1);
    }

    void AutonomousPeriodic() {
    }

  private:
    Hands* m_hands;
    Drive* m_drive;
    Shooter* m_shooter;

    Joystick* joystick0;
    Joystick* joystick1;
};
