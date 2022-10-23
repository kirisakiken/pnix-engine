#include "first_app.hpp"

#include <stdexcept>

namespace pnix {
  FirstApp::FirstApp() {
    createPipelineLayout();
    createPipeline();
    createCommandBuffers();
  }

  FirstApp::~FirstApp() {
    vkDestroyPipelineLayout(pnixDevice.device(), pipelineLayout, nullptr);
  }

  void FirstApp::run() {
    while (!pnixWindow.shouldClose()) {
      glfwPollEvents();
    }
  }

  void FirstApp::createPipelineLayout() {
    VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
    pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutInfo.setLayoutCount = 0;
    pipelineLayoutInfo.pSetLayouts = nullptr;
    pipelineLayoutInfo.pushConstantRangeCount = 0;
    pipelineLayoutInfo.pPushConstantRanges = nullptr;

    if (vkCreatePipelineLayout(pnixDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
      throw std::runtime_error("Failed to create pipeline layout");
    }
  }

  void FirstApp::createPipeline() {
    auto pipelineConfig = PnixPipeline::defaultPipelineConfigInfo(pnixSwapChain.width(), pnixSwapChain.height());
    pipelineConfig.renderPass = pnixSwapChain.getRenderPass();
    pipelineConfig.pipelineLayout = pipelineLayout;
    pnixPipeline = std::make_unique<PnixPipeline>(
        pnixDevice,
        "shaders/simple_shader.vert.spv",
        "shaders/simple_shader.frag.spv",
        pipelineConfig
        );
  }

  void FirstApp::createCommandBuffers() {

  }

  void FirstApp::drawFrame() {

  }
}
