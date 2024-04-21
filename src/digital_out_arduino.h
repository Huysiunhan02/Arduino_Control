#pragma once

#include "digital_out.h"

namespace robot {

/// @brief This class provides an Arduino implementation of the digital output interface.
class DigitalOutArduino : public DigitalOut {
 public:
  /// @brief Constructs a DigitalOutArduino using the specified GPIO pin.
  ///
  /// @param gpio_pin GPIO pin.
  explicit DigitalOutArduino(const int gpio_pin) : DigitalOut(gpio_pin) {}

  void begin() const override;

  void write(int value) const override;
};

}