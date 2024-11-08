
#if defined(__CMD_VERSION__)

#include <iostream>
#include <string>

#include "cipher.hpp"

void run(int argc, char ** argv) {
    
    if (argc < 2) {
      std::cout << "Use -n or -c or -s to select" << std::endl;
    }

    std::string arg(argv[1]);
    if (arg.compare("-n") == 0) {
      std::cout << "Initials..." << std::endl;
      std::string name;
      std::cout << "Enter name: ";
      std::getline(std::cin, name);

      std::cout << "The initials are : " << name_to_initials(name) << std::endl; 
    } 
    else if (arg.compare("-c") == 0) {
      std::cout << "Caesar Cipher..." << std::endl;
      int shift;
      std::cout << "Enter shift: " ;
      std::cin >> shift;
      set_shift(shift);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::string str;
      std::cout << "Enter text to encode: ";
      std::getline(std::cin, str);

      std::cout << "The encoded string is: " << encode(str) << std::endl;
    } 
    else if (arg.compare("-s") == 0) {
      std::cout << "Substitution Cipher..." << std::endl;
      std::string submsg;
      std::cout << "Enter substitution: ";
      std::cin >> submsg;
      substitution_set(submsg);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::string str;
      std::cout << "Enter text to encode: ";
      std::getline(std::cin, str);

      std::cout << "The encoded string is: " << substitution_encode(str) << std::endl;
    } else {
      std::cout << "Use -n or -c or -s to select" << std::endl;
    }
}

#else

#define ASIO_STANDALONE
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <iostream>
#include <thread>

#include <nlohmann/json.hpp>

#include "cipher.hpp"

typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

// pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

// Define a callback to handle incoming messages
void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg) {
    auto payload = msg->get_payload();
    auto incoming = nlohmann::json::parse(payload);
    if (incoming.is_object()) {
        if (incoming["shift"].is_number()) {
            set_shift(incoming["shift"].get<unsigned int>());
        }
        else if (incoming["msg"].is_string()) {
            std::string alpha = incoming["msg"].get<std::string>();
            alpha = encode(alpha);
            s->send(hdl, alpha, msg->get_opcode());
        }
        else if (incoming["sub"].is_string()) {
            std::string alpha = incoming["sub"].get<std::string>();
            substitution_set(alpha);
        }
        else if (incoming["submsg"].is_string()) {
            std::string alpha = incoming["submsg"].get<std::string>();
            alpha = substitution_encode(alpha);
            s->send(hdl, alpha, msg->get_opcode());
        }
        else if (incoming["name"].is_string()) {
            std::string alpha = incoming["name"].get<std::string>();
            alpha = name_to_initials(alpha);
            s->send(hdl, alpha, msg->get_opcode());
        }
    }
    
    if (msg->get_payload() == "stop-listening") {
        s->stop_listening();
        return;
    }

    try {
        //s->send(hdl, msg->get_payload(), msg->get_opcode());
    } catch (websocketpp::exception const & e) {
        std::cout << "Echo failed because: "
                  << "(" << e.what() << ")" << std::endl;
    }
}

void run(int argc, char **argv) {
    server web_server;

    try {
        // Set logging settings
        web_server.set_access_channels(websocketpp::log::alevel::all);
        web_server.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize Asio
        web_server.init_asio();

        // Register our message handler
        web_server.set_message_handler(bind(&on_message,&web_server,::_1,::_2));

        // Listen on port 9002
        web_server.listen(9922);

        // Start the server accept loop
        web_server.start_accept();

        // Start the ASIO io_service run loop
        web_server.run();
    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "other exception" << std::endl;
    }
}

//-----------------------------------------------------------------------------

#endif