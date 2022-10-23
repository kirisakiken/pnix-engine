#pragma once

#include "pnix_window.hpp"
#include "pnix_pipeline.hpp"
#include "pnix_device.hpp"
#include "pnix_swap_chain.hpp"

#include <memory>

namespace pnix {
  class FirstApp {
  public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    FirstApp();
    ~FirstApp();

    FirstApp(const FirstApp&) = delete;
    FirstApp& operator = (const FirstApp&) = delete;

    void run();
  private:
    PnixWindow pnixWindow{WIDTH, HEIGHT, "Hello, Vulkan!"};
    PnixDevice pnixDevice{pnixWindow};
    PnixSwapChain pnixSwapChain{pnixDevice, pnixWindow.getExtent()};
    std::unique_ptr<PnixPipeline> pnixPipeline;
    VkPipelineLayout pipelineLayout;
    std::vector<VkCommandBuffer> commandBuffers;

    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();
  };
}
