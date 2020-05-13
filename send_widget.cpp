#include <fstream>
#include <iostream>
#include <signals/signal.hpp>
#include <cppurses/cppurses.hpp>
#include <biji.hpp>   
#include <spdlog/spdlog.h>

#include "send_widget.hpp"

using namespace cppurses;
using namespace biji;

namespace {
const std::size_t front_page{0};
const std::size_t confirm_page{1};
}  // namespace  

// need another popup_page that flags if entry data fails tests
// ENTER press for send
// inverse attributes on focus

Send_widget::Send_widget()
  : popup{make_page<popup_page>(*this)}
{
    // up and down to navigage options
//    height_policy.fixed(9);
  //  width_policy.fixed(35);

    give_focus_on_change(true);
    focus_policy = Focus_policy::Strong;

    enter_button.brush.set_background(Color::Black);
    enter_button.brush.set_foreground(Color::Dark_blue);  
    enter_button.border.enable();
    enter_button.height_policy.fixed(3);

    enter_address.brush.set_background(Color::Black);
    enter_address.brush.set_foreground(Color::Dark_blue);
    enter_address.set_ghost_color(Color::Dark_blue);
    enter_address.border.enable();
    enter_address.height_policy.fixed(2);

    enter_amount.brush.set_background(Color::Black);
    enter_amount.brush.set_foreground(Color::Dark_blue);
    enter_amount.set_ghost_color(Color::Dark_blue);   
    enter_amount.border.enable();
    enter_amount.height_policy.fixed(2);

    enter_fee.brush.set_background(Color::Black);
    enter_fee.brush.set_foreground(Color::Dark_blue);
    enter_fee.set_ghost_color(Color::Dark_blue);   
    enter_fee.border.enable();
    enter_fee.height_policy.fixed(2);

 //   bool key_press_event();
    //slot::set_attribute(enter_button, Attribute::Inverse);
    set_active_page(front_page);

    enter_button.clicked.connect(
    [this]
    {
        set_active_page(confirm_page);
        popup.execute();
    });
    
/*    if (Key::State == Key::Enter)
    {
        set_active_page(confirm_page);
        popup.execute();
    }*/
/*    const Key::State& keyboard;
    if (keyboard.key == Key::Arrow_down || keyboard.key == Key::j) {
        this->select_down();
    } else if (keyboard.key == Key::Arrow_up || keyboard.key == Key::k) {
        this->select_up();
    } else if (keyboard.key == Key::Enter) {
        this->send_selected_signal();
    }
    return true; */  
};                                     



popup_page::popup_page(Send_widget& send)
  : send_w(send)
{
//    height_policy.fixed(9);
  //  width_policy.fixed(35);

    text_echo.set_alignment(Alignment::Center);
    text_echo.brush.set_foreground(Color::Dark_blue);
    text_echo.border.enable();
    text_echo.height_policy.fixed(2);

    text_confirm.set_alignment(Alignment::Center);
    text_confirm.brush.set_foreground(Color::Dark_blue);
    text_confirm.border.enable();
    text_confirm.height_policy.fixed(3);

    address_echo.set_alignment(Alignment::Center);
    address_echo.brush.set_foreground(Color::Dark_blue);
    address_echo.border.enable();
    address_echo.height_policy.fixed(2);

    fee_echo.set_alignment(Alignment::Center);
    fee_echo.brush.set_foreground(Color::Dark_blue);
    fee_echo.border.enable();
    fee_echo.height_policy.fixed(2);

    amount_echo.set_alignment(Alignment::Center);
    amount_echo.brush.set_foreground(Color::Dark_blue);
    amount_echo.border.enable();
    amount_echo.height_policy.fixed(2);

  //  empty_space.height_policy.fixed(3);

    no_button.clicked.connect(
    [this]()
    {
//    this->Stack::set_active_page(confirm_page);
    });

    no_button.border.enable();
    no_button.height_policy.fixed(4);

    yes_button.clicked.connect(
    [this]()
    {
        build_transaction();
        broadcast();
    });
     
    yes_button.border.enable();
    yes_button.height_policy.fixed(4);


//    auto& esc_short = Shortcuts::add_shortcut(Key::Escape);
//   esc_short.connect([this] { main_menu.goto_menu(); });
}

void popup_page::execute()
{
    spdlog::debug("popup_page::echo_input: Name is: {}",
        send_w.enter_address.contents().str());

    address_echo.set_contents(send_w.enter_address.contents().str());
    
    fee_echo.set_contents(send_w.enter_fee.contents().str());

    amount_echo.set_contents(send_w.enter_amount.contents().str());

    // repeat for all fields
    //std::cout << "Address: {}" << send_w.enter_address.contents().str() << std::endl; 


}

void popup_page::build_transaction()
{
    // builds
}

void popup_page::broadcast()
{
    // broadcasts
}
