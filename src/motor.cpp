#include "motor.h"

#include "digital_out.h"
#include "pwm_out.h"

namespace robot {

void Motor::begin() {
  enable_digital_out_->begin();
  forward_pwm_out_->begin();
  backward_pwm_out_->begin();
}

void Motor::enable(bool enabled) { enable_digital_out_->write(enabled ? 1 : 0); }

void Motor::set_speed(int speed) {
  bool forward = true;

  if (speed < kMinSpeed) {
    speed = -speed;
    forward = false;
  }
  if (speed > kMaxSpeed) {
    speed = kMaxSpeed;
  }

  // The motor speed is controlled by sending a PWM wave to the corresponding pin.
  if (forward) {
    forward_pwm_out_->write(speed);
    backward_pwm_out_->write(0);
  } else {
    backward_pwm_out_->write(speed);
    forward_pwm_out_->write(0);
  }
}

}