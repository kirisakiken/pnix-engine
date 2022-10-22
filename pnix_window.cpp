#include "pnix_window.hpp"

#include <stdexcept>

namespace pnix {
  PnixWindow::PnixWindow(int width, int height, const std::string& windowName)
  : width(width), height(height), windowName(windowName) {
    initWindow();
  }

  PnixWindow::~PnixWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
  }

  bool PnixWindow::shouldClose() {
    return glfwWindowShouldClose(window);
  }

  void PnixWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
      throw std::runtime_error("Failed to create window surface");
  }

  void PnixWindow::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
  }
}
