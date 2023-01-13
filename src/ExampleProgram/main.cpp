#include <version.h>
#include <iostream>
#include <toml.hpp>
#include <unistd.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void showHelp(const char program_name[]);

int main(int argc, char* argv[]) {
    cout << "Started " << argv[0] << ": " << endl << "Version: " << PROJECT_VERSION << endl;      // DIANA convention
/*
    std::string mqtt_ip;
    int mqtt_port;
    std::string toml_config_path = "config/config.toml";

    // Parse argv
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            showHelp(argv[0]);
            exit(0);

        } else if ((arg == "-c") || (arg == "--config")) {
            if (i + 1 < argc) { // Make sure we aren't at the end of argv!
                toml_config_path = std::string(
                        argv[++i]); // Increment 'i' so we don't get the argument as the next argv[i].
            } else { // Uh-oh, there was no argument to the destination option.
                std::cerr << "--destination option requires one argument." << std::endl;
                return 1;
            }
        }
    }

    // Parse MQTT from TOML configuration
    cout << "Parsing TOML configuration" << endl;
    try {
        const auto toml_config = toml::parse(toml_config_path);

        // Parse MQTT configuration from TOML file
        const auto mqtt_config = toml::find(toml_config, "mqtt");
        mqtt_ip = toml::find<std::string>(mqtt_config, "broker_ip");
        mqtt_port = toml::find<int>(mqtt_config, "broker_port");

    } catch (const toml::syntax_error &err) {
        cout << "ERROR: TOML syntax error: " << err.what() << endl;
        cout << "Quiting program..." << endl;
        exit(1);

    } catch (const std::runtime_error &err) {
        cout << "ERROR: TOML: Runtime Error" << endl;
        exit(2);
    }
    cout << "Parsing TOML configuration COMPLETED" << endl;
    cout << "[MQTT] IP:\t" << mqtt_ip << " | PORT: " << mqtt_port << endl;
*/
    // Code for a very smart computation
    for (int i = 1; i <= 1000000; i++) {
        cout << "Smart computation n. " << i << endl;
        usleep(1000 * 1000);
    }

    cout << "Terminated" << endl;   // DIANA convention
    return 0;
}

/**
 * @brief Show an list of all commands to pass from command line
 * @param program_name The name of the program. You can simple use argv[0]
 */
void showHelp(const char program_name[]) {
    cout << program_name << endl;
    cout << "-h, --help\tfor commands details" << endl;
    cout << "-c, --config <config_path>\tto specify TOML configuration file path. Default ./config/config.toml" << endl;
}
