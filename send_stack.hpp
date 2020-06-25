#ifndef DARK_SEND_STACK_HPP
#define DARK_SEND_STACK_HPP 

#include <fstream>
#include <iostream>
#include <signals/signal.hpp>
#include <cppurses/cppurses.hpp>
//#include <biji.hpp>   
#include <spdlog/spdlog.h>

#include "boxes.hpp"

using namespace cppurses;
//using namespace biji;

// tab up and down through stack

class confirm_popup;
class error_popup;
class sending_popup;

class Send_stack
  : public layout::Stack
{
public:

    Send_stack();

    layout::Vertical& send_menu{make_child<layout::Vertical>()};

    address_box& enter_address{send_menu.make_child<address_box>()};

    amount_box& enter_amount{send_menu.make_child<amount_box>()};

    fee_box& enter_fee{send_menu.make_child<fee_box>()};

    Push_button& enter_button{send_menu.make_child<Push_button>("SEND")};    

    confirm_popup& confirm;

    error_popup& error;

    sending_popup& sending;

    //Emitted on Enter Key press, sends along the current contents.  
    sig::Signal<void(const std::string&)> send_data;

    //void set_selected_attribute(const Attribute& attr);

 //   bool key_press_event(const Key::State& keyboard);

    //std::size_t selected_index_{0};

private:

   // Attribute selected_attr_{Attribute::Inverse};
};

class confirm_popup
  : public layout::Vertical
{
public:
    confirm_popup(Send_stack& send);
    
    Textbox& input_echo{make_child<Textbox>()};

    confirm_box& buttons{make_child<confirm_box>()};

    bool key_press_event(const Key::State& keyboard);
    
    void execute();

private:
    void build_transaction();
    void broadcast();
    Send_stack& send_w;
};   

class error_popup
  : public layout::Vertical
{
public:
    error_popup(Send_stack& send);

private:
    Send_stack& send_w;
};

class sending_popup
  : public layout::Vertical
{
public:
    sending_popup(Send_stack& send);

private:
    Send_stack& send_w;

    Status_bar& send_status{make_child<Status_bar>("Sending transaction...")};
};

// get address, amount, fee 
// check 
// build transaction
// are you sure?
// send / broadcast

#endif  // DARK_SEND_STACK_HPP           
