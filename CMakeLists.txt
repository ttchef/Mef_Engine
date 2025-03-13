
cmake_minimum_required(VERSION 3.20.0)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello)

#Get OS Architecture
set(OSBitness 32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

#set output dir
set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}-${OSBitness}/${CMAKE_BUILD_TYPE}")
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static-libs")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")


#MEF_ENGINE
include_directories("mef_engine/extern/")
include_directories("mef_engine/")
add_library(mef_lib STATIC mef_engine/mef.cpp mef_engine/circleObj/mef_circle.cpp mef_engine/Utils.cpp)

target_include_directories(mef_lib PUBLIC 
    ${CMAKE_SOURCE_DIR}/mef_engine/extern/
    ${CMAKE_SOURCE_DIR}/mef_engine/
    ${CMAKE_SOURCE_DIR}/mef_engine/circleObj/
)
# Target-Link-Libraries für mef_lib hinzufügen
target_link_libraries(mef_lib PUBLIC glad glfw)

#GLFW
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
)
option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_INSTALL OFF)
FetchContent_MakeAvailable(glfw)

#GLAD
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG v0.1.36
)
FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
    FetchContent_Populate(glad)
    
    # Glad Konfigurationen
    set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
    set(GLAD_API "gl=4.6" CACHE STRING "API type/version pairs, like \"gl=4.6,gles=\", no version means latest")
    set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
    
    # Füge das CMakeLists.txt von Glad hinzu
    add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif()

#GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
)
FetchContent_GetProperties(glm)
if(NOT glm_POPULATED)
    FetchContent_Populate(glm)
    # GLM ist header-only, wir müssen einfach nur den Include-Pfad setzen
    add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
endif()


#ImGui
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.90.4  # Du kannst hier eine spezifische Version wählen
)
FetchContent_GetProperties(imgui)
if(NOT imgui_POPULATED)
    FetchContent_Populate(imgui)
    
    # ImGui ist keine normale CMake-Bibliothek, daher müssen wir sie manuell hinzufügen
    set(IMGUI_SOURCES
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        # GLFW-Backend
        ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    )
    
    add_library(imgui STATIC ${IMGUI_SOURCES})
    target_include_directories(imgui PUBLIC 
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
    )
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE mef_lib glfw glad glm imgui)

#OpenGL
if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
endif()


