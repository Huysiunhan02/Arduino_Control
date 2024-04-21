#pragma once

#include "digital_out.h"
#include "pwm_out.h"

namespace robot {

/// @brief This class allows to control a DC motor by enabling it and setting its speed. The
/// involved pins are expected to be connected to a full-bridge motor driver module, such as the
/// L298N.
class Motor {
 public:
  /// @brief Constructs a new Motor object.
  ///
  /// @param enable_digital_out Digital output connected to motor enable pin.
  /// @param forward_pwm_out PWM output connected to motor forward pin.
  /// @param backward_pwm_out PWM output connected to motor backward pin.
  Motor(const DigitalOut* enable_digital_out, const PwmOut* forward_pwm_out,
        const PwmOut* backward_pwm_out)
      : enable_digital_out_(enable_digital_out),
        forward_pwm_out_(forward_pwm_out),
        backward_pwm_out_(backward_pwm_out) {}

  /// @brief Initializes the motor.
  void begin();

  /// @brief Enables the motor.
  ///
  /// @param enabled True to enable the motor, false otherwise.
  void enable(bool enabled);

  /// @brief Sets the motor speed.
  ///
  /// @param speed Motor speed value.
  void set_speed(int speed);

 private:
  /// Minimum speed value (negative speeds are considered as positive backward speeds).
  static constexpr int kMinSpeed{0};

  /// Maximum speed value.
  static constexpr int kMaxSpeed{255};

  /// Digital output connected to motor enable pin.
  const DigitalOut* enable_digital_out_;

  /// PWM output connected to motor forward pin.
  const PwmOut* forward_pwm_out_;

  /// PWM output connected to motor backward pin.
  const PwmOut* backward_pwm_out_;
};

}