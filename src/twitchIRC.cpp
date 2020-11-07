/**
 * @author      : worldpotato
 * @file        : twitchIRC
 * @created     : Sunday Oct 25, 2020 18:39:45 CET
 */
#include <iostream>
#include <string>

#include "twitchIRC.hpp"
#include "helper/config.hpp"

twitchIRC::twitchIRC()
{
    const std::string configPath = "config.yaml";
    config IRCconfig = config();
    // config IRCconfig = config();
    IRCconfig.readConfig(configPath);

    std::cout << "[twitchIRC] init twitchIRC with the following configs" << "\r\n";
    std::cout << "\r\n";

    std::cout << "channel: " << IRCconfig.getChannel() << "\r\n";
    std::cout << "user: " << IRCconfig.getUser() << "\r\n";
    std::cout << "Server: " << IRCconfig.getServer() << "\r\n";
    std::cout << "ServerPort: " << IRCconfig.getServerPort() << "\r\n";
    std::cout << "Password: " << IRCconfig.getPassword() << "\r\n";

}

twitchIRC::~twitchIRC()
{
}

