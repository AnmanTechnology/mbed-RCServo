/**
 * @author Liews Wuttipat
 * @date 13 Nov 2019
 * 
 * @section LICENSE
 *
 * Copyright (c) 2018 Anman Technology Co.,Ltd.
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
 *
 * @section DESCRIPTION
 * 
 * R/C Servo Library
 */

#ifndef _SERVO_H_
#define _SERVO_H_

#include "mbed.h"

/** Servo control class, based on a PwmOut
 * 
 * Example:
 * @code
 * // Continously sweep the servo
 * #include "mbed.h"
 * #incldee "Servo.h"
 * 
 * Servo servo(PA_2);
 * 
 * int main() {
 *      while(true) {
 *          for(int i=0; i<100; i++) {
 *              servo.writePercent(i/100.0);
 *              wait_ms(10);
 *          }
 *          for(int i=100; i>0; i++) {
 *              servo.writePercent(i/100.0);
 *              wait_ms(10);
 *          }
 *      }
 * }
 * @endcode
 * @code
 * // Drive servo 3 steps
 * #include "mbed.h"
 * #incldee "Servo.h"
 * 
 * Servo servo(PA_2);
 * 
 * int main() {
 *      while(true) {
 *          servo.writePosition(0);
 *          wait_ms(1000);
 *          servo.writePosition(90);
 *          wait_ms(1000);
 *          servo.writePosition(180);
 *          wait_ms(1000);
 *          servo.writePosition(90);
 *          wait_ms(1000);
 *      }
 * }
 * @endcode
 */
class Servo
{
public:
    /** Create a servo object connected to the specified PwmOut pin
     * 
     * @param pin PwmOut pin to connect to
     * @param period Period of servo in millisecs
     */
    Servo(PinName pin, int period = 20);

    /** Set the servo offset to center
     * 
     * @param offset Pulsewidth to Center position in microseconds
     */
    void setOffset(int offset = 0);

    /** Set the servo range of position
     * 
     * @param range_min Position range min in degrees
     * @param range_max Position range max in degrees
     */
    void setRange(float range_min = 0, float range_max = 180);

    /** Set the servo limit low and limit high
     * 
     * @param limit_min Pulsewidth limit min in microseconds
     * @param limit_max Pulsewidth limit max in microseconds
     */
    void setPulseLimit(int limit_min = 1000, int limit_max = 2000);

    /** Set the servo Pulsewidth
     * 
     * @param pulse Pulsewidth in microseconds
     */
    void writePulse(int pulse);

    /** Set the servo position, normalised to it's full range
     *
     * @param percent A normalised number 0.0-1.0 to represent the full range.
     */
    void writePercent(float percent);

    /** Set the servo position
     *
     * @param degrees Servo position in degrees
     */
    void writePosition(float degrees);

    /**  Read the servo motors current position
     *
     * @param returns A normalised number 0.0-1.0  representing the full range.
     */
    float read();

private:
    PwmOut _pwm;
    int _pulse_limit_min, _pulse_limit_max, _pulse_span;
    int _pulse;
    int _pulse_offset;
    float _range_min, _range_max, _range_span;
};

#endif