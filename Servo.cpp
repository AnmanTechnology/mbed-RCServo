#include "Servo.h"
#include "mbed.h"

#define CONSTRAIN(x, lower, upper) ((x) < (lower) ? (lower) : ((x) > (upper) ? (upper) : (x)))

Servo::Servo(PinName pin, int period) : _pwm(pin)
{
    _pwm.period_ms(period);
    _pulse = 0;
    setPulseLimit();
    setRange();
    setOffset();
}

void Servo::setOffset(int offset)
{
    _pulse_offset = offset;
}

void Servo::setRange(float range_min, float range_max)
{
    _range_min = range_min;
    _range_max = range_max;
    _range_span = _range_max - _range_min;
}

void Servo::setPulseLimit(int limit_min, int limit_max)
{
    _pulse_limit_min = limit_min;
    _pulse_limit_max = limit_max;
    _pulse_span = _pulse_limit_max - _pulse_limit_min;
}

void Servo::writePulse(int pulse)
{
    _pulse = CONSTRAIN(pulse + _pulse_offset, _pulse_limit_min, _pulse_limit_max);
    _pwm.pulsewidth_us(_pulse);
}

void Servo::writePercent(float percent)
{
    percent = CONSTRAIN(percent, 0.0, 1.0);
    writePulse(int(percent * _pulse_span) + _pulse_limit_min);
}

void Servo::writePosition(float degrees)
{
    degrees = CONSTRAIN(degrees, _range_min, _range_max);
    writePercent((degrees - _range_min) / _range_span);
}

float Servo::read()
{
    return _pulse;
}
