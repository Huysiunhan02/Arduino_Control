#pragma once

#include "pwm_out.h"

namespace robot {

/// @brief This class provides an Arduino implementation of the PWM output interface.
class PwmOutArduino : public PwmOut {
 public:
  /// @brief Constructs a PwmOutArduino using the specified GPIO pin.
  ///
  /// @param gpio_pin GPIO pin.
  explicit PwmOutArduino(const int gpio_pin) : PwmOut(gpio_pin) {}

  void begin() const override;

  void write(int value) const override;
};

} 