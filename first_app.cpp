#include "first_app.hpp"

namespace pnix {
  void FirstApp::run() {
    while (!pnixWindow.shouldClose()) {
      glfwPollEvents();
    }
  }
}
