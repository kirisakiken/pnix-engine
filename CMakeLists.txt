cmake_minimum_required(VERSION 3.20)
project(pnix_engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(pnix_engine main.cpp
        pnix_window.cpp
        pnix_pipeline.cpp
        pnix_device.cpp
        pnix_swap_chain.cpp
        first_app.cpp)
