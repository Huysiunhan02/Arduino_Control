#pragma once

namespace robot {

/// @brief CLI commands.
struct Commands {
  /// @brief Reads an analog GPIO.
  static constexpr const char* kReadAnalogGpio{"a"};
  /// @brief Reads a digital GPIO.
  static constexpr const char* kReadDigitalGpio{"d"};
  /// @brief Sets the motors PWM value [duty range: 0-255].
  static constexpr const char* kSetMotorsPwm{"o"};
};

}