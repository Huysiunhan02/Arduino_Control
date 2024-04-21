#include "app.h"

#include <Arduino.h>

#include "commands.h"
#include "constants.h"
#include "digital_out_arduino.h"
#include "hw.h"
#include "motor.h"
#include "pwm_out_arduino.h"
#include "serial_stream_arduino.h"
#include "shell.h"

namespace robot{
SerialStreamArduino App::serial_stream_;

Shell App::shell_;

//wheel left
DigitalOutArduino App::left_motor1_enable_digital_out_(Hw::kLeftMotor1EnableGpioPin);
PwmOutArduino App::left_motor1_forward_pwm_out_(Hw::kLeftMotor1ForwardGpioPin);
PwmOutArduino App::left_motor1_backward_pwm_out_(Hw::kLeftMotor1BackwardGpioPin);
Motor App::left_motor1_(&left_motor1_enable_digital_out_, &left_motor1_forward_pwm_out_,
                       &left_motor1_backward_pwm_out_);
DigitalOutArduino App::left_motor2_enable_digital_out_(Hw::kLeftMotor2EnableGpioPin);
PwmOutArduino App::left_motor2_forward_pwm_out_(Hw::kLeftMotor2ForwardGpioPin);
PwmOutArduino App::left_motor2_backward_pwm_out_(Hw::kLeftMotor2BackwardGpioPin);
Motor App::left_motor2_(&left_motor2_enable_digital_out_, &left_motor2_forward_pwm_out_,
                       &left_motor2_backward_pwm_out_);
DigitalOutArduino App::left_motor3_enable_digital_out_(Hw::kLeftMotor3EnableGpioPin);
PwmOutArduino App::left_motor3_forward_pwm_out_(Hw::kLeftMotor3ForwardGpioPin);
PwmOutArduino App::left_motor3_backward_pwm_out_(Hw::kLeftMotor3BackwardGpioPin);
Motor App::left_motor3_(&left_motor3_enable_digital_out_, &left_motor3_forward_pwm_out_,
                       &left_motor3_backward_pwm_out_);                       

//wheel right
DigitalOutArduino App::right_motor1_enable_digital_out_(Hw::kRightMotor1EnableGpioPin);
PwmOutArduino App::right_motor1_forward_pwm_out_(Hw::kRightMotor1ForwardGpioPin);
PwmOutArduino App::right_motor1_backward_pwm_out_(Hw::kRightMotor1BackwardGpioPin);
Motor App::right_motor1_(&right_motor1_enable_digital_out_, &right_motor1_forward_pwm_out_,
                        &right_motor1_backward_pwm_out_);
DigitalOutArduino App::right_motor2_enable_digital_out_(Hw::kRightMotor2EnableGpioPin);
PwmOutArduino App::right_motor2_forward_pwm_out_(Hw::kRightMotor2ForwardGpioPin);
PwmOutArduino App::right_motor2_backward_pwm_out_(Hw::kRightMotor2BackwardGpioPin);
Motor App::right_motor2_(&right_motor2_enable_digital_out_, &right_motor2_forward_pwm_out_,
                        &right_motor2_backward_pwm_out_);
DigitalOutArduino App::right_motor3_enable_digital_out_(Hw::kRightMotor3EnableGpioPin);
PwmOutArduino App::right_motor3_forward_pwm_out_(Hw::kRightMotor3ForwardGpioPin);
PwmOutArduino App::right_motor3_backward_pwm_out_(Hw::kRightMotor3BackwardGpioPin);
Motor App::right_motor3_(&right_motor3_enable_digital_out_, &right_motor3_forward_pwm_out_,
                        &right_motor3_backward_pwm_out_);

unsigned long App::last_pid_computation_{0};

unsigned long App::last_set_motors_speed_cmd_{0};

void App::setup() {
  // Required by Arduino libraries to work.
  init();

  serial_stream_.begin(Constants::kBaudrate);
  Serial.println("Start config....");

  left_motor1_.begin();
  left_motor1_.enable(true);
  left_motor2_.begin();
  left_motor2_.enable(true);
  left_motor3_.begin();
  left_motor3_.enable(true);

  right_motor1_.begin();
  right_motor1_.enable(true);
  right_motor2_.begin();
  right_motor2_.enable(true);
  right_motor3_.begin();
  right_motor3_.enable(true);

  // Initialize command shell.
  shell_.set_serial_stream(&serial_stream_);
  shell_.set_default_callback(cmd_unknown_cb);
  shell_.register_command(Commands::kReadAnalogGpio, cmd_read_analog_gpio_cb);
  shell_.register_command(Commands::kReadDigitalGpio, cmd_read_digital_gpio_cb);
  shell_.register_command(Commands::kSetMotorsPwm, cmd_set_motors_pwm_cb);
  Serial.println("Done!");

}
void App::loop() {
  // Process command prompt input.
  shell_.process_input();
  // delay(2000);

  // Compute PID output at the configured rate.
  // if ((millis() - last_pid_computation_) > Constants::kPidPeriod) {
  //   last_pid_computation_ = millis();
  //   adjust_motors_speed();
  // }


  // Stop the motors if auto-stop interval has been reached.
  if ((millis() - last_set_motors_speed_cmd_) > Constants::kAutoStopWindow) {
    last_set_motors_speed_cmd_ = millis();
    stop_motors();
  }


  // Required by Arduino libraries to work.
  if (serialEventRun) {
    serialEventRun();
  }
}

void App::stop_motors() {
  left_motor1_.set_speed(0);
  left_motor2_.set_speed(0);
  left_motor3_.set_speed(0);

  right_motor1_.set_speed(0);
  right_motor2_.set_speed(0);
  right_motor3_.set_speed(0);

}

void App::cmd_unknown_cb(int, char**) { Serial.println("Unknown command."); }

void App::cmd_read_analog_gpio_cb(int argc, char** argv) {
  if (argc < 2) {
    return;
  }

  const int pin = atoi(argv[1]);
  Serial.println(analogRead(pin));
}

void App::cmd_read_digital_gpio_cb(int argc, char** argv) {
  if (argc < 2) {
    return;
  }

  const int pin = atoi(argv[1]);
  Serial.println(digitalRead(pin));
}

void App::cmd_set_motors_pwm_cb(int argc, char** argv) {
  if (argc < 3) {
    return;
  }

  const int left_motor_pwm = atoi(argv[1]);
  const int right_motor_pwm = atoi(argv[2]);
  left_motor1_.set_speed(left_motor_pwm);
  left_motor2_.set_speed(left_motor_pwm);
  left_motor3_.set_speed(left_motor_pwm);

  right_motor1_.set_speed(right_motor_pwm);
  right_motor2_.set_speed(right_motor_pwm);
  right_motor3_.set_speed(right_motor_pwm);

  Serial.println("OK");
}
}