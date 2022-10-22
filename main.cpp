#include "first_app.hpp"

#include <cstdlib>
#include <stdexcept>
#include <iostream>

int main() {
  pnix::FirstApp app{};

  try {
    app.run();
  } catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
