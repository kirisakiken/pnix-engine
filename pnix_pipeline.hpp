#pragma once

#include "pnix_device.hpp"

#include <string>
#include <vector>

namespace pnix {
  struct PipelineConfigInfo {
    VkViewport viewport;
    VkRect2D scissor;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
  };

  class PnixPipeline {
  public:
    PnixPipeline(
        PnixDevice& device,
        const std::string& vertFilePath,
        const std::string& fragFilePath,
        const PipelineConfigInfo& configInfo
        );
    ~PnixPipeline();
    PnixPipeline(const PnixPipeline&) = delete;
    void operator=(const PnixPipeline&) = delete;

    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

  private:
    static std::vector<char> readFile(const std::string& filePath); // can be moved to file extensions
    void createGraphicsPipeline(
        const std::string& vertFilePath,
        const std::string& fragFilePath,
        const PipelineConfigInfo& configInfo
        );

    void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

    PnixDevice& pnixDevice;
    VkPipeline graphicsPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;
  };
}
