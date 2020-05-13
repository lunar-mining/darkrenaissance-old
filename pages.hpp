#ifndef DARK_PAGES_HPP
#define DARK_PAGES_HPP

#include <cppurses/cppurses.hpp>
#include <biji.hpp>   
#include "send_widget.hpp"

using namespace cppurses;
using namespace biji;

class send_page
  : public layout::Horizontal
{
public:
    send_page();

    Send_widget& send_function
    {
        make_child<Send_widget>()
    };    
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

class landing_page
  : public layout::Horizontal
{
public:
    landing_page();

    Text_display& text
    {
        make_child<Text_display>("WELCOME TO THE WALLET")
    };
};

#endif // DARK_PAGES_HPP
