#include "digital_out_arduino.h"

#include <Arduino.h>

namespace robot {

void DigitalOutArduino::begin() const { pinMode(gpio_pin_, OUTPUT); }

void DigitalOutArduino::write(int value) const { digitalWrite(gpio_pin_, value); }

}