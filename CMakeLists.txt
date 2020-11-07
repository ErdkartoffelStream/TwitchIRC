######################################################################
# @author      : worldpotato
# @file        : CMakeLists
# @created     : Tuesday Aug 25, 2020 08:23:38 CEST
######################################################################

cmake_minimum_required(VERSION 3.17)
project(twitchIRC)

add_compile_options(-lpthread -Wall)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

set(TESTS OFF CACHE BOOL "Defines if the tests should be build or not")

add_subdirectory(lib)

add_library(twitchIRC STATIC
    src/twitchIRC.cpp
    src/helper/config.cpp
)

target_link_libraries(twitchIRC yaml-cpp)

target_include_directories(twitchIRC PUBLIC include)

if(TESTS)
    include(CTest)
    add_subdirectory(tests)

    add_custom_command(TARGET twitchIRC POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/tests/testSuites/test_configs
        ${CMAKE_BINARY_DIR}/tests/test_configs
    )
endif()
