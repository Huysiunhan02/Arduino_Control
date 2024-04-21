#pragma once

namespace robot {

struct Hw {

//wheel left
  static constexpr int kLeftMotor1BackwardGpioPin{2};
  static constexpr int kLeftMotor1ForwardGpioPin{3};
  static constexpr int kLeftMotor1EnableGpioPin{20};

  static constexpr int kLeftMotor2BackwardGpioPin{4};
  static constexpr int kLeftMotor2ForwardGpioPin{5};
  static constexpr int kLeftMotor2EnableGpioPin{21};

  static constexpr int kLeftMotor3BackwardGpioPin{6};
  static constexpr int kLeftMotor3ForwardGpioPin{7};
  static constexpr int kLeftMotor3EnableGpioPin{22};

//wheel right
  static constexpr int kRightMotor1BackwardGpioPin{8};
  static constexpr int kRightMotor1ForwardGpioPin{9};
  static constexpr int kRightMotor1EnableGpioPin{23};

  static constexpr int kRightMotor2BackwardGpioPin{10};
  static constexpr int kRightMotor2ForwardGpioPin{11};
  static constexpr int kRightMotor2EnableGpioPin{24};

  static constexpr int kRightMotor3BackwardGpioPin{12};
  static constexpr int kRightMotor3ForwardGpioPin{13};
  static constexpr int kRightMotor3EnableGpioPin{25};
};

}