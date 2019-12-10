#include <mbed.h>
#include "Servo.h"

#define LED_BUILTIN PC_13
#define SERIAL_TX PB_6
#define SERIAL_RX PB_7

Serial serial(SERIAL_TX, SERIAL_RX, 9600);
DigitalOut led(LED_BUILTIN);
Servo servo(PA_2, 16);

int main()
{
    serial.printf("STM32 bluepill mbed test.\n");
    // servo.setOffset(0.00005); //45MG996R
    // servo.calibrate(0.00085);MG996R
    // servo.calibrate(0.00025);
    // servo.writePercent(100.0);
    // servo.writePercent(0.0);
    // wait_ms(3000);
    // float off = 0.3;
    while (1)
    {
        // servo.writePercent(0.5);
        // wait_ms(3000);
        for (int i = 500; i < 640; i++)
        {
            // serial.printf("%d\n", i);
            servo.writePercent(i / 1000.0);
            wait_ms(50);
        }
        for (int i = 640; i < 680; i++)
        {
            // serial.printf("%d\n", i);
            servo.writePercent(i / 1000.0);
            wait_ms(50);
        }
        for (int i = 680; i > 640; i--)
        {
            // serial.printf("%d\n", i);
            servo.writePercent(i / 1000.0);
            wait_ms(50);
        }
        for (int i = 640; i > 500; i--)
        {
            // serial.printf("%d\n", i);
            servo.writePercent(i / 1000.0);
            wait_ms(50);
        }

        // servo.write(0);
        // wait_ms(1000);
        // servo.write(0.5);
        // wait_ms(1000);
        // servo.write(1.0);
        // wait_ms(1000);
        // servo.write(0.5);
        // wait_ms(1000);
    }
}