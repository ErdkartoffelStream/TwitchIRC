find_package(Threads REQUIRED)

enable_testing()


include_directories(../include)

add_executable(twitchIRC_tests
    mainTests.cpp
    ../src/helper/config.cpp
    ./testSuites/test_config.cpp
)

target_link_libraries(twitchIRC_tests
    gtest
    gmock
    yaml-cpp
)

add_test(
    NAME twitchIRC_tests
    COMMAND twitchIRC_tests
)

