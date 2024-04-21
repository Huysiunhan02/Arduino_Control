#pragma once
#include <stdio.h>

namespace robot
{
    class SerialStream
    {
    public:
        enum Base
        {
            kBin = 2,
            kOct = 8,
            kDec = 10,
            kHex = 16,
        };
        explicit SerialStream() = default;

        virtual ~SerialStream() = default;

        virtual void begin(unsigned long baud) const = 0;

        virtual int available() const = 0;

        virtual int read() const = 0;

        virtual size_t print(const char *c) const = 0;

        virtual size_t print(char c) const = 0;

        virtual size_t print(unsigned char b, int base = kDec) const = 0;

        virtual size_t print(int num, int base = kDec) const = 0;

        virtual size_t print(unsigned int num, int base = kDec) const = 0;

        virtual size_t print(long num, int base = kDec) const = 0;

        virtual size_t print(unsigned long num, int base = kDec) const = 0;

        virtual size_t print(double num, int digits = 2) const = 0;

        virtual size_t println(const char *c) const = 0;

        virtual size_t println(char c) const = 0;

        virtual size_t println(unsigned char b, int base = kDec) const = 0;

        virtual size_t println(int num, int base = kDec) const = 0;

        virtual size_t println(unsigned int num, int base = kDec) const = 0;

        virtual size_t println(long num, int base = kDec) const = 0;

        virtual size_t println(unsigned long num, int base = kDec) const = 0;

        virtual size_t println(double num, int digits = 2) const = 0;
    };
}