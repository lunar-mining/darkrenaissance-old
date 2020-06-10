#ifndef DARK_PAGES_HPP
#define DARK_PAGES_HPP

#include <cppurses/cppurses.hpp>
//#include <biji.hpp>   
#include "send_widget.hpp"

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

    Send_stack& send_widget{make_child<Send_stack>()};    

    bool key_press_event(const Key::State& keyboard);
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
