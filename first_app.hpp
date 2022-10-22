#pragma once

#include "pnix_window.hpp"
#include "pnix_pipeline.hpp"
#include "pnix_device.hpp"

namespace pnix {
  class FirstApp {
  public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void run();
  private:
    PnixWindow pnixWindow{WIDTH, HEIGHT, "Hello, Vulkan!"};
    PnixDevice pnixDevice{pnixWindow};
    PnixPipeline pnixPipeline{
      pnixDevice,
      "shaders/simple_shader.vert.spv",
      "shaders/simple_shader.frag.spv",
      pnixPipeline.defaultPipelineConfigInfo(WIDTH, HEIGHT)
    };
  };
}
