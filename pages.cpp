#include "pages.hpp"
#include "gui.hpp"
#include <cppurses/cppurses.hpp>
//#include <biji.hpp>     

//using namespace biji;

landing_page::landing_page()
{   
  //  Focus::set_focus_to(*this);         
    focus_policy = Focus_policy::Direct;
    set_name("landing page");
    text.set_alignment(Alignment::Center);
    text.brush.set_foreground(Color::Dark_blue);
}

send_page::send_page()
{
   // Focus::set_focus_to(*this);
    focus_policy = Focus_policy::Strong;
    set_name("send page");
}

receive_page::receive_page()
{
    //Focus::set_focus_to(*this);
    focus_policy = Focus_policy::Direct;
    text.set_alignment(Alignment::Center);
    set_name("receive page");
}

balance_page::balance_page()
{
    //Focus::set_focus_to(*this);
    focus_policy = Focus_policy::Direct;
    text.set_alignment(Alignment::Center);
    set_name("balance page");
} 

history_page::history_page()
{
    //Focus::set_focus_to(*this);
    focus_policy = Focus_policy::Direct;
    text.set_alignment(Alignment::Center);
    set_name("history page");
}                               

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
    }
    return Widget::key_press_event(keyboard);
}

/* void send_page::set_selected_attribute(const Attribute& attr)
{
    auto& selected_btn = items_[selected_index_].button.get();
    selected_btn.brush.remove_attributes(selected_attr_);
    selected_attr_ = attr;
    selected_btn.brush.add_attributes(selected_attr_);
    selected_btn.update();
}*/
