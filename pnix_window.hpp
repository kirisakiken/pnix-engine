#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace pnix {
  class PnixWindow {
  public:
    PnixWindow(int width, int height, const std::string& window_name);
    ~PnixWindow();
    PnixWindow(const PnixWindow&) = delete;
    PnixWindow &operator = (const PnixWindow&) = delete;

    bool shouldClose();
    VkExtent2D getExtent() const;
    void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

  private:
    const int width;
    const int height;
    const std::string windowName;
    GLFWwindow* window;

    void initWindow();
  };
}
