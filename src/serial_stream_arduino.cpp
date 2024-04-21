#include "serial_stream_arduino.h"

#include <stdio.h>

#include <Arduino.h>

namespace robot {

void SerialStreamArduino::begin(unsigned long baud) const { Serial.begin(baud); }

int SerialStreamArduino::available() const { return Serial.available(); }

int SerialStreamArduino::read() const { return Serial.read(); }

size_t SerialStreamArduino::print(const char* c) const { return Serial.print(c); }

size_t SerialStreamArduino::print(char c) const { return Serial.print(c); }

size_t SerialStreamArduino::print(unsigned char b, int base) const { return Serial.print(b, base); }

size_t SerialStreamArduino::print(int num, int base) const { return Serial.print(num, base); }

size_t SerialStreamArduino::print(unsigned int num, int base) const {
  return Serial.print(num, base);
}

size_t SerialStreamArduino::print(long num, int base) const { return Serial.print(num, base); }

size_t SerialStreamArduino::print(unsigned long num, int base) const {
  return Serial.print(num, base);
}

size_t SerialStreamArduino::print(double num, int digits) const {
  return Serial.print(num, digits);
}

size_t SerialStreamArduino::println(const char* c) const { return Serial.println(c); }

size_t SerialStreamArduino::println(char c) const { return Serial.println(c); }

size_t SerialStreamArduino::println(unsigned char b, int base) const {
  return Serial.println(b, base);
}

size_t SerialStreamArduino::println(int num, int base) const { return Serial.println(num, base); }

size_t SerialStreamArduino::println(unsigned int num, int base) const {
  return Serial.println(num, base);
}

size_t SerialStreamArduino::println(long num, int base) const { return Serial.println(num, base); }

size_t SerialStreamArduino::println(unsigned long num, int base) const {
  return Serial.println(num, base);
}

size_t SerialStreamArduino::println(double num, int digits) const {
  return Serial.println(num, digits);
}

}