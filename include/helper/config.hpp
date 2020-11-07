/**
 * @author      : worldpotato
 * @file        : config
 * @created     : Sunday Oct 25, 2020 19:20:43 CET
 */

#ifndef CONFIG_HPP

#define CONFIG_HPP

#include "yaml-cpp/yaml.h"
#include <string>

class config
{
    public:
        config(std::string configPath);
        config();
        virtual ~config();
        /**
         * Reads the config from the parameter configPath
         **/
        void readConfig(std::string configPath);
        std::string getUser();
        std::string getPassword();
        std::string getChannel();
        std::string getServer();
        std::string getServerPort();

    private:
        std::string user;
        std::string password;
        std::string server;
        std::string serverPort;
        std::string channel;

        void readUserFromConfigFile(YAML::Node);
        void readPasswordFromConfigFile(YAML::Node);
        void readChannelFromConfigFile(YAML::Node);
        void readServerFromConfigFile(YAML::Node);
        void readServerPortFromConfigFile(YAML::Node);
};

#endif /* end of include guard CONFIG_HPP */

