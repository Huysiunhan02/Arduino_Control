#pragma once

namespace robot {

/// @brief This class defines an interface for digital inputs.
class DigitalIn {
 public:
  /// @brief Constructs a DigitalIn using the specified GPIO pin.
  ///
  /// @param gpio_pin GPIO pin.
  explicit DigitalIn(const int gpio_pin) : gpio_pin_(gpio_pin) {}

  /// @brief Destructs the digital input.
  virtual ~DigitalIn() = default;

  /// @brief Initializes the digital input.
  virtual void begin() const = 0;

  /// @brief Gets the digital input value (0 or 1).
  ///
  /// @return Digital input value.
  virtual int read() const = 0;

 protected:
  /// GPIO pin.
  const int gpio_pin_;
};

} 