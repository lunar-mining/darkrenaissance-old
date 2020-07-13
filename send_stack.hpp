#ifndef DARK_SEND_STACK_HPP
#define DARK_SEND_STACK_HPP 

#include <fstream>
#include <iostream>
#include <signals/signal.hpp>
#include <cppurses/cppurses.hpp>
//#include <biji.hpp>   
#include <spdlog/spdlog.h>
#include <array>
#include "boxes.hpp"


using namespace cppurses;
//using namespace biji;

// tab up and down through stack

class confirm_popup;
class error_popup;
class sending_popup;

class send_stack
  : public layout::Stack
{
public:

    send_stack();

    //TODO: possibly refactor into one input per page

    //layout::Vertical& send_menu{make_child<layout::Vertical>()};

    address_box& enter_address{make_child<address_box>()};

    amount_box& enter_amount{make_child<amount_box>()};

    fee_box& enter_fee{make_child<fee_box>()};

   // Push_button& enter_button{make_child<Push_button>("SEND")};    

    confirm_popup& confirm;

    error_popup& error;

    sending_popup& sending;

   // void select_item(std::size_t index);

   // void select_up(std::size_t n = 1);

   // void select_down(std::size_t n = 1);

   // void set_selected_attribute(const Attribute& attr);

    //Emitted on Enter Key press, sends along the current contents.  

    sig::Signal<void(const std::string&)> send_data;

private:

    /*std::array<Push_button, 4> button_array{address_box.address_prompt, 
                                        amount_box.amount_prompt,
                                        fee_box.fee_prompt,
                                        enter_button};*/

    /*struct send_stack_item
    {
        //explicit send_stack_item(Push_button& ref) : button{ref} {};
       // std::reference_wrapper<Push_button> button;
        address_box& enter_address;
        amount_box& enter_amount;
        fee_box& enter_fee;
        Push_button& enter_button;
        sig::Signal<void()> selected;
    };

    std::vector<send_stack_item> items;
    //std::size_t selected_index_{0};
    //Attribute selected_attr_{Attribute::Inverse};

    void send_selected_signal();*/
};

/*sig::Slot<void(std::size_t)> select_up(send_stack& m);
sig::Slot<void()> select_up(send_stack& m, std::size_t n);

sig::Slot<void(std::size_t)> select_down(send_stack& m);
sig::Slot<void()> select_down(send_stack& m, std::size_t n);

sig::Slot<void(std::size_t)> select_item(send_stack& m);
sig::Slot<void()> select_item(send_stack& m, std::size_t index);*/

class confirm_popup
  : public layout::Vertical
{
public:
    confirm_popup(send_stack& send);
    
    Textbox& input_echo{make_child<Textbox>()};

    confirm_box& buttons{make_child<confirm_box>()};

    bool key_press_event(const Key::State& keyboard);
    
    void execute();

private:
    void build_transaction();
    void broadcast();
    send_stack& send_w;
};   

class error_popup
  : public layout::Vertical
{
public:
    error_popup(send_stack& send);

private:
    send_stack& send_w;
};

class sending_popup
  : public layout::Vertical
{
public:
    sending_popup(send_stack& send);

private:
    send_stack& send_w;

    Status_bar& send_status{make_child<Status_bar>("Sending transaction...")};
};

// get address, amount, fee 
// check 
// build transaction
// are you sure?
// send / broadcast

#endif  // DARK_SEND_STACK_HPP           
