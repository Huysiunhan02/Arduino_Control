#pragma once

namespace robot {

/// @brief This class defines an interface for digital outputs.
class DigitalOut {
 public:
  /// @brief Constructs a DigitalOut using the specified GPIO pin.
  ///
  /// @param gpio_pin GPIO pin.
  explicit DigitalOut(const int gpio_pin) : gpio_pin_(gpio_pin) {}

  /// @brief Destructs the digital output.
  virtual ~DigitalOut() = default;

  /// @brief Initializes the digital output.
  virtual void begin() const = 0;

  /// @brief Sets the digital output value (0 or 1).
  ///
  /// @param value Digital output value.
  virtual void write(int value) const = 0;

 protected:
  /// GPIO pin.
  const int gpio_pin_;
};

}