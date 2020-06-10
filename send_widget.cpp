#include <fstream>
#include <iostream>
#include <signals/signal.hpp>
#include <cppurses/cppurses.hpp>
//#include <biji.hpp>   
#include <spdlog/spdlog.h>

#include "send_widget.hpp"

using namespace cppurses;
//using namespace biji;

namespace {
const std::size_t front_page{0};
const std::size_t confirm_page{1};
}    

// need another popup_page that flags if entry data fails tests
// ENTER press for send
// inverse attributes on focus

Send_stack::Send_stack()
  : popup{make_page<popup_page>(*this)}
{
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

    set_active_page(front_page);
    set_name("send stack");

    give_focus_on_change(true);
    
    if (Focus::focus_widget())
        spdlog::debug("hhh focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("hhh none");
 
    enter_button.brush.set_background(Color::Black);
    enter_button.brush.set_foreground(Color::Blue);  
    enter_button.border.enable();
    enter_button.height_policy.expanding(3);
    
    enter_button.clicked.connect(
    [this]
    {
    if (Focus::focus_widget())
        spdlog::debug("focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("none");
        set_active_page(confirm_page);
        popup.execute();
    });
};                                     

popup_page::popup_page(Send_stack& send)
  : send_w(send)
{
    set_name("popup page");
    focus_policy = Focus_policy::Direct;

   // input_echo.border.enable();
  //  input_echo.set_alignment(Alignment::Center);

    input_echo.height_policy.expanding(7);

    input_echo.width_policy.expanding(35);

 //   no_button.clicked.connect(
 //   [this]()
 //   {
 //  //   wallet_menu.goto_menu;
 //   });

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

void popup_page::execute()
{
    Glyph_string input_data = "You entered:" +
        send_w.enter_address.address_input.contents().str() +
        send_w.enter_fee.fee_input.contents().str() +
        send_w.enter_amount.amount_input.contents().str();

    input_echo.set_contents(input_data);
}

void popup_page::build_transaction()
{
    // builds
}

void popup_page::broadcast()
{
    // broadcasts
}

