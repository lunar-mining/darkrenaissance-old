#ifndef DARK_SEND_WIDGET_HPP
#define DARK_SEND_WIDGET_HPP 

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

class popup_page;

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

    popup_page& popup;

    //Emitted on Enter Key press, sends along the current contents.  
    sig::Signal<void(const std::string&)> send_data;
};

class popup_page
  : public layout::Vertical
{
public:
    popup_page(Send_stack& send);
    
    Textbox& input_echo{make_child<Textbox>()};

    confirm_box& buttons{make_child<confirm_box>()};
    
   // bool key_press_event(const Key::State& keyboard) override;

 //   void select_up(std::size_t n = 1);

  //  void select_down(std::size_t n = 1);

    void execute();

private:
    void build_transaction();
    void broadcast();
    Send_stack& send_w;
};   

// get address, amount, fee 
// check 
// build transaction
// are you sure?
// send / broadcast

#endif  // DARK_SEND_WIDGET_HPP           
