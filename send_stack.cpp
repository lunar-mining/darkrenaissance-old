#include <fstream>
#include <iostream>
#include <signals/signal.hpp>
#include <cppurses/cppurses.hpp>
//#include <biji.hpp>   
#include <spdlog/spdlog.h>

#include "send_stack.hpp"

using namespace cppurses;
//using namespace biji;

namespace {
const std::size_t front_page{0};
const std::size_t confirm_page{1};
const std::size_t error_page{2};
const std::size_t sending_page{3};
}    

// need another confirm_popup that flags if entry data fails tests
// ENTER press for send
// inverse attributes on focus

Send_stack::Send_stack()
  : confirm{make_page<confirm_popup>(*this)},
    error{make_page<error_popup>(*this)},
    sending{make_page<sending_popup>(*this)}
{
    set_active_page(front_page);
    set_name("send stack");
    give_focus_on_change(true);

    send_menu.focus_policy = Focus_policy::Direct;
    send_menu.set_name("send_menu");

    enter_address.set_name("address box");
    enter_address.focus_policy = Focus_policy::Direct;

    enter_amount.set_name("amount box");
    enter_amount.focus_policy = Focus_policy::Direct;

    enter_fee.set_name("fee box");
    enter_fee.focus_policy = Focus_policy::Direct;

    enter_button.set_name("button box");
    enter_button.focus_policy = Focus_policy::Direct;
    enter_button.brush.set_background(Color::Black);
    enter_button.brush.set_foreground(Color::Blue);  
    enter_button.border.enable();
    enter_button.height_policy.expanding(3);

    // focus debugger
    if (Focus::focus_widget())
        spdlog::debug("hhh focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("hhh none");
 
    // focus check on click
    enter_button.clicked.connect(
    [this]
    {
    if (Focus::focus_widget())
        spdlog::debug("focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("none");
        set_active_page(confirm_page);
        confirm.execute();
    });
};                                     

confirm_popup::confirm_popup(Send_stack& send)
  : send_w(send)
{
    set_name("popup page");
    focus_policy = Focus_policy::Direct;

    input_echo.border.enable();
    input_echo.height_policy.expanding(7);
    input_echo.width_policy.expanding(35);

    buttons.no_button.clicked.connect(
    [this]()
    {
        send_w.set_active_page(front_page);
    });

    buttons.yes_button.clicked.connect(
    [this]()
    {
        send_w.set_active_page(sending_page);
    });
 //   no_button.border.enable();
 //   no_button.height_policy.expanding(4);

 //   yes_button.clicked.connect(
 //   [this]()
 //   {
 //      // build_transaction();
 //       //broadcast();
 //   });
 //    
 //   yes_button.border.enable();
 //   yes_button.height_policy.expanding(4);
}

void confirm_popup::execute()
{
    Glyph_string input_data = "You entered:\n" +
        send_w.enter_address.address_input.contents().str() + "\n" +
        send_w.enter_fee.fee_input.contents().str() + "\n" +
        send_w.enter_amount.amount_input.contents().str();

    input_echo.set_contents(input_data);
}


bool confirm_popup::key_press_event(const Key::State& keyboard) {
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
        send_w.set_active_page(3);
    }
    return Widget::key_press_event(keyboard);
}


void confirm_popup::build_transaction()
{
    // builds
}

void confirm_popup::broadcast()
{
    // broadcasts
}

error_popup::error_popup(Send_stack& send)
  : send_w(send)
{
}

sending_popup::sending_popup(Send_stack& send)
  : send_w(send)
{
}
