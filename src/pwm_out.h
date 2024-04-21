#pragma once

namespace robot {

/// @brief This class defines an interface for PWM outputs.
class PwmOut {
 public:
  /// @brief Constructs a PwmOut using the specified GPIO pin.
  ///
  /// @param gpio_pin GPIO pin.
  explicit PwmOut(const int gpio_pin) : gpio_pin_(gpio_pin) {}

  /// @brief Destructs the PWM output.
  virtual ~PwmOut() {}

  /// @brief Initializes the PWM output.
  virtual void begin() const = 0;

  /// @brief Sets the PWM output value (0 to 255).
  ///
  /// @param value PWM value.
  // TODO(jballoffet): Change this API to expect values from 0 to 100 (%).
  virtual void write(int value) const = 0;

 protected:
  /// GPIO pin.
  const int gpio_pin_;
};

}