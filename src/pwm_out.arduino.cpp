#include "pwm_out_arduino.h"

#include <Arduino.h>

namespace robot {

void PwmOutArduino::begin() const { pinMode(gpio_pin_, OUTPUT); }

void PwmOutArduino::write(int value) const { analogWrite(gpio_pin_, value); }

} 