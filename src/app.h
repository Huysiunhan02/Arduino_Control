#pragma once

#include "digital_out_arduino.h"
#include "motor.h"
#include "pwm_out_arduino.h"
#include "serial_stream_arduino.h"
#include "shell.h"

namespace robot {

/// @brief This class wraps the MCU main application.
class App {
 public:
  /// This class only contains static members.
  App() = delete;

  /// @brief Configures and sets the application up. Meant to be called once at startup.
  static void setup();

  /// @brief Application main run loop. Meant to be called continously.
  static void loop();

 private:
  /// Computes the PID output and updates the motors speed accordingly.
  static void adjust_motors_speed();

  /// Stops the motors and disables the PID.
  static void stop_motors();

  /// Callback method for an unknown command (default).
  static void cmd_unknown_cb(int argc, char** argv);

  /// Callback method for the `Commands::kReadAnalogGpio` command.
  static void cmd_read_analog_gpio_cb(int argc, char** argv);

  /// Callback method for the `Commands::kReadDigitalGpio` command.
  static void cmd_read_digital_gpio_cb(int argc, char** argv);

  /// Callback method for the `Commands::kSetMotorsPwm` command.
  static void cmd_set_motors_pwm_cb(int argc, char** argv);

  /// Serial stream.
  static SerialStreamArduino serial_stream_;

  /// Application command shell.
  static Shell shell_;

  /// Left wheel motor 1.
  static DigitalOutArduino left_motor1_enable_digital_out_;
  static PwmOutArduino left_motor1_forward_pwm_out_;
  static PwmOutArduino left_motor1_backward_pwm_out_;
  static Motor left_motor1_;
   /// Left wheel motor 2.
  static DigitalOutArduino left_motor2_enable_digital_out_;
  static PwmOutArduino left_motor2_forward_pwm_out_;
  static PwmOutArduino left_motor2_backward_pwm_out_;
  static Motor left_motor2_;
   /// Left wheel motor 3.
  static DigitalOutArduino left_motor3_enable_digital_out_;
  static PwmOutArduino left_motor3_forward_pwm_out_;
  static PwmOutArduino left_motor3_backward_pwm_out_;
  static Motor left_motor3_;

  /// Right wheel motor 1.
  static DigitalOutArduino right_motor1_enable_digital_out_;
  static PwmOutArduino right_motor1_forward_pwm_out_;
  static PwmOutArduino right_motor1_backward_pwm_out_;
  static Motor right_motor1_;
  /// Right wheel motor 2.
  static DigitalOutArduino right_motor2_enable_digital_out_;
  static PwmOutArduino right_motor2_forward_pwm_out_;
  static PwmOutArduino right_motor2_backward_pwm_out_;
  static Motor right_motor2_;
    /// Right wheel motor 3.
  static DigitalOutArduino right_motor3_enable_digital_out_;
  static PwmOutArduino right_motor3_forward_pwm_out_;
  static PwmOutArduino right_motor3_backward_pwm_out_;
  static Motor right_motor3_;
  
  /// Tracks the last time the PID computation was made.
  static unsigned long last_pid_computation_;

  /// Tracks the last time a `Commands::kSetMotorsSpeed` command was received.
  static unsigned long last_set_motors_speed_cmd_;
};

}