#ifndef BOXES_HPP
#define BOXES_HPP   

#include <cppurses/cppurses.hpp>
//#include <biji.hpp>

using namespace cppurses;
//using namespace biji;

class address_box
  : public layout::Horizontal  
{
public:
    address_box();

    Push_button& address_prompt{make_child<Push_button>("Enter address")};

    Fixed_width& address_separator{make_child<Fixed_width>(1)};

    Line_edit& address_input{make_child<Line_edit>(" Address")};

    sig::Signal<void(std::string&)> address_entered;
};

class amount_box
  : public layout::Horizontal
{
public:
    amount_box();

    Push_button& amount_prompt{make_child<Push_button>("Enter amount")};

    Fixed_width& amount_separator{make_child<Fixed_width>(1)};

    Line_edit& amount_input{this->make_child<Line_edit>(" Amount")};

    sig::Signal<void(std::string&)> amount_entered;
};

class fee_box
  : public layout::Horizontal
{
public:
    fee_box();

    Push_button& fee_prompt{make_child<Push_button>("Enter fee")};

    Fixed_width& fee_separator{make_child<Fixed_width>(1)};

    Line_edit& fee_input{this->make_child<Line_edit>(" Fee")};

    sig::Signal<void(std::string&)> fee_entered;
}; 

class confirm_box
  : public layout::Horizontal
{
public:
    confirm_box();

    Text_display& confirm_text{make_child<Text_display>("Are you sure?")};

    Fixed_width& confirm_separator{make_child<Fixed_width>(1)};

    Push_button& yes_button{make_child<Push_button>("YES")};

    Push_button& no_button{make_child<Push_button>("NO")};
};

#endif // BOXES_HPP
