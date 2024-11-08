#pragma once

#define ASIO_STANDALONE
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <nlohmann/json.hpp>

#include <iostream>
#include <string>
#include <thread> 


typedef websocketpp::server<websocketpp::config::asio> server;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

// pull out the type of messages sent by our config
typedef server::message_ptr message_ptr;

std::string rpn_eval(std::string expr);


// Define a callback to handle incoming messages
inline void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg) {
    auto payload = msg->get_payload();
    auto incoming = nlohmann::json::parse(payload);
    if (incoming.is_object()) {
        if (incoming["expr"].is_string()) {
            std::string alpha = incoming["expr"].get<std::string>();
            alpha = rpn_eval(alpha);
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

inline void run() {
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


