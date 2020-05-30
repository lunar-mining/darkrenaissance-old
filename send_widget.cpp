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
}    

// need another popup_page that flags if entry data fails tests
// ENTER press for send
// inverse attributes on focus

Send_widget::Send_widget()
  : popup{make_page<popup_page>(*this)}
{
    give_focus_on_change(true);
    focus_policy = Focus_policy::Strong;

    enter_button.brush.set_background(Color::Black);
    enter_button.brush.set_foreground(Color::Blue);  
    enter_button.border.enable();
    enter_button.height_policy.expanding(3);

 //   bool key_press_event();
    //slot::set_attribute(enter_button, Attribute::Inverse);
    set_active_page(front_page);

    enter_button.clicked.connect(
    [this]
    {
        set_active_page(confirm_page);
        popup.execute();
    });
    
    /*const Key::State& keyboard;
    if (keyboard.key == Key::Enter)
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
//    height_policy.expanding(9);
    width_policy.expanding(35);

    text_echo.set_alignment(Alignment::Center);
    text_echo.brush.set_foreground(Color::Blue);
    text_echo.height_policy.expanding(1);

    text_confirm.set_alignment(Alignment::Center);
    text_confirm.brush.set_foreground(Color::Blue);
    text_confirm.height_policy.expanding(3);

    address_echo.set_alignment(Alignment::Center);
    address_echo.brush.set_foreground(Color::Blue);
    address_echo.height_policy.expanding(2);

    fee_echo.set_alignment(Alignment::Center);
    fee_echo.brush.set_foreground(Color::Blue);
    fee_echo.height_policy.expanding(2);

    amount_echo.set_alignment(Alignment::Center);
    amount_echo.brush.set_foreground(Color::Blue);
    //amount_echo.border.enable();
    //amount_echo.height_policy.expanding(2);

  //  empty_space.height_policy.expanding(3);

    no_button.clicked.connect(
    [this]()
    {
//    this->Stack::set_active_page(confirm_page);
    });

    no_button.border.enable();
    no_button.height_policy.expanding(4);

    yes_button.clicked.connect(
    [this]()
    {
        build_transaction();
        broadcast();
    });
     
    yes_button.border.enable();
    yes_button.height_policy.expanding(4);


//    auto& esc_short = Shortcuts::add_shortcut(Key::Escape);
//   esc_short.connect([this] { main_menu.goto_menu(); });
}

void popup_page::execute()
{
    spdlog::debug("popup_page::echo_input: Name is: {}",
        send_w.enter_address.address_input.contents().str());

    address_echo.set_contents(send_w.enter_address.address_input.contents().str());
    
    fee_echo.set_contents(send_w.enter_fee.fee_input.contents().str());

    amount_echo.set_contents(send_w.enter_amount.amount_input.contents().str());

    // repeat for all fields
    std::cout << "Address: {}" << send_w.enter_address.address_input.contents().str() << std::endl; 
}

void popup_page::build_transaction()
{
    // builds
}

void popup_page::broadcast()
{
    // broadcasts
}
