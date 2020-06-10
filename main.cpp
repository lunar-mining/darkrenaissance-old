#include <iostream> 
#include "pages.hpp"
#include "gui.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <cppurses/cppurses.hpp>
//#include <biji.hpp>

//using namespace biji;

void setup_logger()
{
    auto file_logger = spdlog::basic_logger_mt("dark_tests", "/tmp/dark_tests.txt");
    file_logger->flush_on(spdlog::level::debug);
    spdlog::set_default_logger(file_logger);            

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug

    spdlog::debug("spdlog initialized.");
}

int main()
{
/*    std::vector<bcs::ec_secret> keys;
    load_keys(keys, "wallet.dat");

    if (is_testnet)
    {
        std::cout << "Running on testnet" << std::endl;
    } */

    setup_logger();

    System sys;
    wallet_gui gui;
    System::set_initial_focus(&gui.wallet_menu); 
    
    auto& esc_short = Shortcuts::add_shortcut(Key::q);
    esc_short.connect([&sys, &gui]
    {
        sys.exit();
    }); 

    return sys.run(gui);      
}                                 
