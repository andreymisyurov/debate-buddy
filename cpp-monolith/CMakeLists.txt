cmake_minimum_required(VERSION 3.10)
project(DebateBuddy)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.12.0
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(json)

find_package(ALSA REQUIRED)

add_subdirectory(cpp-logger)

set(SOURCES
    src/main.cpp
    src/audio/AudioCapture.cpp
)

add_executable(debate-buddy ${SOURCES})

target_include_directories(debate-buddy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${ALSA_INCLUDE_DIRS}
)

target_link_libraries(debate-buddy PRIVATE 
    Logger
    ${ALSA_LIBRARIES}
)