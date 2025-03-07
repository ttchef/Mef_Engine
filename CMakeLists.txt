
cmake_minimum_required(VERSION 3.20.0)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(Hello)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory(mef_engine/src)

add_executable(Hello project1/src/main.cpp)
target_link_libaries

