#include "pages.hpp"
#include "gui.hpp"
#include <cppurses/cppurses.hpp>
//#include <biji.hpp>     

//using namespace biji;

landing_page::landing_page()
{   
  //  Focus::set_focus_to(*this);         
    spdlog::debug("landing page constructor called");
    focus_policy = Focus_policy::Direct;
    set_name("landing page");
    text.set_alignment(Alignment::Center);
    text.brush.set_foreground(Color::Dark_blue);
}

send_page::send_page()
{
    spdlog::debug("send page constructor called");
    Focus::set_focus_to(send_widget);
    spdlog::debug("focus set to send widgets");
   if (Focus::focus_widget())
        spdlog::debug("Focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("None"); 
    focus_policy = Focus_policy::Strong;
    spdlog::debug("Focus policy set to strong");
    set_name("send page");
    send_widget.set_name("send widget");
}

receive_page::receive_page()
{
    //Focus::set_focus_to(*this);
    spdlog::debug("receive page constructor called");
    focus_policy = Focus_policy::Direct;
    text.set_alignment(Alignment::Center);
    set_name("receive page");
}

balance_page::balance_page()
{
    //Focus::set_focus_to(*this);
    spdlog::debug("balance page constructor called");
    focus_policy = Focus_policy::Direct;
    text.set_alignment(Alignment::Center);
    set_name("balance page");
} 

history_page::history_page()
{
    //Focus::set_focus_to(*this);
    spdlog::debug("balance page constructor called");
    focus_policy = Focus_policy::Direct;
    text.set_alignment(Alignment::Center);
    set_name("history page");
}                               

// send page menu key presses happen here
bool send_page::key_press_event(const Key::State& keyboard) {
    spdlog::debug("Key press function called");
    if (keyboard.key == Key::Arrow_left) {
        spdlog::debug("Left arrow pushed");
    } else if (keyboard.key == Key::Arrow_right) {
        spdlog::debug("Right arrow pushed");
    } else if (keyboard.key == Key::Arrow_up) {
        spdlog::debug("Up arrow pushed");
    } else if (keyboard.key == Key::Arrow_down) {
        spdlog::debug("Down arrow pushed");
    } else if (keyboard.key == Key::Enter) {
        spdlog::debug("Enter pushed");
        send_widget.set_active_page(1);
        spdlog::debug("confirm page set");
        send_widget.confirm.execute();
    }
    return Widget::key_press_event(keyboard);
}

