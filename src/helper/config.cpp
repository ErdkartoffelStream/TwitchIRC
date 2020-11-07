/**
 * @author      : worldpotato
 * @file        : config
 * @created     : Sunday Oct 25, 2020 19:20:16 CET
 */

#include "helper/config.hpp"
#include <iostream>

config::config()
{

}

config::config(std::string configPath)
{
    readConfig(configPath);
}

void config::readConfig(std::string configPath)
{
    YAML::Node yaml = YAML::LoadFile(configPath);

    readUserFromConfigFile(yaml);
    readPasswordFromConfigFile(yaml);
    readChannelFromConfigFile(yaml);
    readServerFromConfigFile(yaml);
    readServerPortFromConfigFile(yaml);
}

std::string config::getUser()
{
    return this->user;
}

std::string config::getPassword()
{
    return this->password;
}

std::string config::getChannel()
{
    return this->channel;
}

std::string config::getServer()
{
    return this->server;
}

std::string config::getServerPort()
{
    return this->serverPort;
}

void config::readUserFromConfigFile(YAML::Node yaml){

    try{
        this->user = yaml["username"].as<std::string>();
    }
    catch(...)
    {
        std::cout << "[config] no username specified default is used" << "\r\n";
        // according to this side: https://github.com/domsson/libtwirc/wiki/Twitch-docs-supplement
        // this is a way to create a anonymous connection
        this->user = "justinfan02935487";
    }
}

void config::readPasswordFromConfigFile(YAML::Node yaml){

    try{
        this->password = yaml["password"].as<std::string>();
    }
    catch(...)
    {
        std::cout << "[config] no password specified a number is used" << "\r\n";
        // according to this side: https://github.com/domsson/libtwirc/wiki/Twitch-docs-supplement
        // this is a way to create a anonymous connection
        this->password = "askajlsdhf";
    }
}

void config::readChannelFromConfigFile(YAML::Node yaml){

    try{
        this->channel = yaml["channel"].as<std::string>();
    }
    catch(...)
    {
        std::cout << "[config] no channel specified the default is used" << "\r\n";
        // this is my channel
        this->channel = "erdkartoffel";
    }
}

void config::readServerFromConfigFile(YAML::Node yaml){

    try{
        this->server = yaml["server"].as<std::string>();
    }
    catch(...)
    {
        std::cout << "[config] no server specified the default is used" << "\r\n";
        // this is the server from twitch
        this->server = "https://twitchapps.com/tmi/";
    }
}

void config::readServerPortFromConfigFile(YAML::Node yaml){

    try{
        this->serverPort = yaml["serverPort"].as<std::string>();
    }
    catch(...)
    {
        std::cout << "[config] no serverPort specified the default is used" << "\r\n";
        // this is the  standard port from the twitch server
        this->serverPort = "6667";
    }

}

config::~config()
{

}

