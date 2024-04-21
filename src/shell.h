#pragma once

#include <stddef.h>

#include "serial_stream.h"

namespace robot {

class Shell {
 public:
  typedef void (*CommandCallback)(int argc, char** argv);

  void set_serial_stream(const SerialStream* serial_stream);

  void set_default_callback(CommandCallback callback);

  void register_command(const char* name, CommandCallback callback);

  void process_input();

 private:
  static constexpr int kCommandNameLengthMax{8};

  struct Command {
    char name[kCommandNameLengthMax];
    CommandCallback callback;
  };

  static constexpr int kCommandsMax{16};

  static constexpr int kCommandArgMax{16};

  static constexpr int kCommandPromptLengthMax{64};

  void parse_message();

  void execute_callback(int argc, char** argv);

  const SerialStream* serial_stream_{nullptr};

  CommandCallback default_callback_{nullptr};

  Command commands_[kCommandsMax];

  size_t commands_count_{0};

  char message_buffer_[kCommandPromptLengthMax];

  int message_index_{0};
};

} 