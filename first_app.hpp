#pragma once

#include "pnix_window.hpp"
#include "pnix_pipeline.hpp"
#include "pnix_device.hpp"
#include "pnix_swap_chain.hpp"

#include <memory>
#include <vector>

namespace pnix {
  class FirstApp {
  public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    FirstApp();
    ~FirstApp();

    FirstApp(const FirstApp&) = delete;
    FirstApp &operator=(const PnixWindow&) = delete;

    void run();

  private:
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();

    PnixWindow pnixWindow{WIDTH, HEIGHT, "Hello, Vulkan!"};
    PnixDevice pnixDevice{pnixWindow};
    PnixSwapChain pnixSwapChain{pnixDevice, pnixWindow.getExtent()};
    std::unique_ptr<PnixPipeline> pnixPipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;
  };
}
