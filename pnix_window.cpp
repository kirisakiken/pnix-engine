#include "pnix_window.hpp"

#include <stdexcept>

namespace pnix {
  PnixWindow::PnixWindow(const int& width, const int& height, const std::string& name)
  : width(width), height(height), windowName(name) {
    initWindow();
  }

  PnixWindow::~PnixWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
  }

  bool PnixWindow::shouldClose() {
    return glfwWindowShouldClose(window);
  }

  VkExtent2D PnixWindow::getExtent() {
    return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
  }

  void PnixWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
      throw std::runtime_error("failed to create window surface");
  }

  void PnixWindow::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // disables creating OpenGL context
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // disable window resizing

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
  }
}
