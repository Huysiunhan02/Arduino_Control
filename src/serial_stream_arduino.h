#pragma once

#include <stdio.h>

#include "serial_stream.h"

namespace robot {

class SerialStreamArduino : public SerialStream {
 public:
  explicit SerialStreamArduino() : SerialStream() {}

  void begin(unsigned long baud) const override;

  int available() const override;

  int read() const override;

  size_t print(const char* c) const override;

  size_t print(char c) const override;

  size_t print(unsigned char b, int base) const override;

  size_t print(int num, int base) const override;

  size_t print(unsigned int num, int base) const override;

  size_t print(long num, int base) const override;

  size_t print(unsigned long num, int base) const override;

  size_t print(double num, int digits) const override;

  size_t println(const char* c) const override;

  size_t println(char c) const override;

  size_t println(unsigned char b, int base) const override;

  size_t println(int num, int base) const override;

  size_t println(unsigned int num, int base) const override;

  size_t println(long num, int base) const override;

  size_t println(unsigned long num, int base) const override;

  size_t println(double num, int digits) const override;
};

}