#pragma once

namespace robot {

/// @brief Common constants.
struct Constants {
  /// @brief Serial port baud rate.
  static constexpr long kBaudrate{57600};

  /// @brief Time window to automatically stop the robot if no command has been received [ms].
  static constexpr long kAutoStopWindow{3000};

  /// @brief Minimum PWM wave duty cycle (0%) (see
  static constexpr int kPwmMin{0};
  /// @brief Maximum PWM wave duty cycle (100%) (see
  static constexpr int kPwmMax{255};

  /// @brief PID computation rate [Hz].
  static constexpr int kPidRate{30};
  /// @brief PID computation period [ms].
  static constexpr double kPidPeriod{1000 / kPidRate};
};

}