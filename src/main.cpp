#include "app.h"

int main(void) {
  // Application configuration.
  robot::App::setup();

  // Application main run loop.
  while (1) {
    robot::App::loop();
  }

  return 0;
}