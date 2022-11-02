#pragma once

#include "pnix_device.hpp"
#include <vector>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

namespace pnix {
  class PnixModel {
  public:
    struct Vertex{
      glm::vec2 position;
      static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
      static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
    };

    PnixModel(PnixDevice& pnixDevice, const std::vector<Vertex>& vertices);
    ~PnixModel();

    PnixModel(const PnixModel&) = delete;
    PnixModel &operator=(const PnixModel&) = delete;

    void bind(VkCommandBuffer commandBuffer);
    void draw(VkCommandBuffer commandBuffer);

  private:
    void createVertexBuffers(const std::vector<Vertex>& vertices);

    PnixDevice& pnixDevice;
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    uint32_t vertexCount;
  };
}
