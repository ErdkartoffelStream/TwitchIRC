/**
 * @author      : worldpotato
 * @file        : test_config
 * @created     : Saturday Oct 31, 2020 17:04:23 CET
 */

#include "helper/config.hpp"
#include <gtest/gtest.h>
#include <string>
 
TEST(ConfigTest, ConstructorCleanConfig) {

    std::string configPath = "test_configs/test_clean_config.yaml";
    config my_test_config = config(configPath);

    ASSERT_EQ("my_test_server", my_test_config.getServer());
    ASSERT_EQ("my_test_channel", my_test_config.getChannel());
    ASSERT_EQ("123456", my_test_config.getServerPort());
    ASSERT_EQ("my_test_password", my_test_config.getPassword());
    ASSERT_EQ("my_test_username", my_test_config.getUser());

}

TEST(ConfigTest, ConstructorEmptyConfig) {

    std::string configPath = "test_configs/test_empty_config.yaml";
    config my_test_config = config(configPath);

    ASSERT_EQ("https://twitchapps.com/tmi/", my_test_config.getServer());
    ASSERT_EQ("erdkartoffel", my_test_config.getChannel());
    ASSERT_EQ("6667", my_test_config.getServerPort());
    ASSERT_EQ("askajlsdhf", my_test_config.getPassword());
    ASSERT_EQ("justinfan02935487", my_test_config.getUser());

}
