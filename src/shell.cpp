#include "shell.h"

#include <string.h>

namespace robot {

void Shell::set_serial_stream(const SerialStream* serial_stream) { serial_stream_ = serial_stream; }

void Shell::set_default_callback(CommandCallback callback) { default_callback_ = callback; }

void Shell::register_command(const char* name, CommandCallback callback) {
  if (commands_count_ >= kCommandsMax) {
    return;
  }

  Command command;
  strcpy(command.name, name);
  command.callback = callback;
  commands_[commands_count_++] = command;
}

void Shell::process_input() {
  while (serial_stream_->available() > 0) {
    const char input = serial_stream_->read();

    switch (input) {
      case '\r':

        // Terminate command prompt message and parse it.
        message_buffer_[message_index_++] = '\0';
        parse_message();
        // Reset message buffer.
        message_index_ = 0;
        break;

      case '\n':
        // Ignore newline characters.
        break;

      default:
        message_buffer_[message_index_++] = input;
        // Prevent buffer overflow.
        if (message_index_ >= kCommandPromptLengthMax) {
          message_index_ = 0;
        }
        break;
    }
  }
}

void Shell::parse_message() {
  char* argv[kCommandArgMax];
  int argc = 0;

  argv[argc] = strtok(message_buffer_, " ");
  while (argv[argc] != NULL && argc < (kCommandArgMax - 1)) {
    argv[++argc] = strtok(NULL, " ");
  }

  execute_callback(argc, argv);
}

void Shell::execute_callback(int argc, char** argv) {
  for (size_t i = 0; i < commands_count_; i++) {
    if (!strcmp(argv[0], commands_[i].name)) {
      commands_[i].callback(argc, argv);
      return;
    }
  }

  // Unknown command received, executing default callback.
  if (default_callback_ != nullptr) {
    default_callback_(argc, argv);
  }
}

}