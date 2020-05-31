#include <cppurses/cppurses.hpp>
#include <biji.hpp>

#include "boxes.hpp"

using namespace biji;

address_box::address_box()
{
    height_policy.fixed(3);

    address_prompt.width_policy.fixed(14);
    address_prompt.brush.set_foreground(Color::Blue);

    address_separator.width_policy.fixed(1);
    address_separator.wallpaper = L'⏵';
     
    address_input.width_policy.fixed(35);
    address_input.brush.set_foreground(Color::Blue);
    address_input.set_ghost_color(Color::Dark_gray);

    border.enable();
}

amount_box::amount_box()
{
    height_policy.fixed(3);

    amount_prompt.width_policy.fixed(13);
    amount_prompt.brush.set_foreground(Color::Blue);

    amount_separator.width_policy.fixed(1);
    amount_separator.wallpaper = L'⏵';

    amount_input.width_policy.fixed(35);
    amount_input.brush.set_foreground(Color::Black);
    amount_input.set_ghost_color(Color::Dark_gray);

    border.enable();
}

fee_box::fee_box()
{
    height_policy.fixed(3);

    fee_prompt.width_policy.fixed(10);
    fee_prompt.brush.set_foreground(Color::Blue);

    fee_separator.width_policy.fixed(1);
    fee_separator.wallpaper = L'⏵';
    
    fee_input.width_policy.fixed(35);
    fee_input.brush.set_foreground(Color::Black);
    fee_input.set_ghost_color(Color::Dark_gray);

    border.enable();
}

