#ifndef DARK_PAGES_HPP
#define DARK_PAGES_HPP

#include <cppurses/cppurses.hpp>
//#include <biji.hpp>   
#include "send_stack.hpp"

using namespace cppurses;
//using namespace biji;

class landing_page
  : public layout::Horizontal
{
public:
    landing_page();

    // would be great to put financial data here

    Text_display& text
    {
        make_child<Text_display>()
    };
};  

class send_page
  : public layout::Horizontal
{
public:
    send_page();

    send_stack& send_widget{make_child<send_stack>()};    

    bool key_press_event(const Key::State& keyboard);

    //void set_selected_attribute(const Attribute& attr);

    //void select_down(std::size_t n = 1);

    //std::size_t selected_index_{0};

    //void select_item(std::size_t index);
private:

    //Attribute selected_attr_{Attribute::Inverse};

};

class receive_page
  : public layout::Horizontal
{
public:
    receive_page();

    Text_display& text
    {
        make_child<Text_display>("Recieve bitcoin here")
    };
}; 

class balance_page
  : public layout::Horizontal
{
public:
    balance_page();

    Text_display& text
    {
        make_child<Text_display>("Ur balance is shit lol")
    };
}; 

class history_page
  : public layout::Horizontal
{
public:
    history_page();

    Text_display& text
    {
        make_child<Text_display>("Show history here")
    };
}; 



#endif // DARK_PAGES_HPP
