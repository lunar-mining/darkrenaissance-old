#ifndef DARK_SEND_WIDGET_HPP
#define DARK_SEND_WIDGET_HPP 

#include <fstream>
#include <iostream>
#include <signals/signal.hpp>
#include <cppurses/cppurses.hpp>
#include <biji.hpp>   
#include <spdlog/spdlog.h>

#include "boxes.hpp"

using namespace cppurses;
using namespace biji;

// tab up and down through stack

class popup_page;
class Send_widget
  : public layout::Stack
{
public:

    Send_widget();

    layout::Vertical& fields{make_child<layout::Vertical>()};

    address_box& enter_address{fields.make_child<address_box>()};

    amount_box& enter_amount{fields.make_child<amount_box>()};

    fee_box& enter_fee{fields.make_child<fee_box>()};

    Push_button& enter_button{fields.make_child<Push_button>("SEND")};    

    popup_page& popup;

    //Emitted on Enter Key press, sends along the current contents.  
    sig::Signal<void(const std::string&)> send_data;
    
protected:
    bool key_press_event();
};

class popup_page
  : public layout::Horizontal
{
public:
    popup_page(Send_widget& send);

    layout::Vertical& left_side{make_child<layout::Vertical>()};
    
    Text_display& text_echo{left_side.make_child<Text_display>("You entered:")};

    //Textbox& input_echo

    Text_display& address_echo{left_side.make_child<Text_display>()};

    Text_display& fee_echo{left_side.make_child<Text_display>()};

    Text_display& amount_echo{left_side.make_child<Text_display>()};

    layout::Vertical& right_side{make_child<layout::Vertical>()};

    Text_display& text_confirm{right_side.make_child<Text_display>("Are you sure?")}; 

    Widget& empty_space{right_side.make_child<Widget>()};

    layout::Horizontal& buttons{right_side.make_child<layout::Horizontal>()};

    Push_button& yes_button{buttons.make_child<Push_button>("YES")};

    Push_button& no_button{buttons.make_child<Push_button>("NO")};
    
    void execute();

private:
    void build_transaction();
    void broadcast();
    Send_widget& send_w;
};   

// get address, amount, fee 
// check 
// build transaction
// are you sure?
// send / broadcast

#endif  // DARK_SEND_WIDGET_HPP           
