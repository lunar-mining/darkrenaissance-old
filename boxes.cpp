#include <cppurses/cppurses.hpp>
//#include <biji.hpp>

#include "boxes.hpp"

//using namespace biji;

address_box::address_box()
{
    set_name("address box");
    address_input.set_name("address input box");
    focus_policy = Focus_policy::Direct;

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
    set_name("amount box");
    amount_input.set_name("amount input box");
    focus_policy = Focus_policy::Direct;

    height_policy.fixed(3);

    amount_prompt.width_policy.fixed(14);
    amount_prompt.brush.set_foreground(Color::Blue);

    amount_separator.width_policy.fixed(1);
    amount_separator.wallpaper = L'⏵';

    amount_input.width_policy.fixed(35);
    amount_input.brush.set_foreground(Color::Blue);
    amount_input.set_ghost_color(Color::Dark_gray);

    border.enable();
}

fee_box::fee_box()
{
    set_name("fee box");
    fee_input.set_name("fee input box");
    focus_policy = Focus_policy::Direct;

    height_policy.fixed(3);

    fee_prompt.width_policy.fixed(14);
    fee_prompt.brush.set_foreground(Color::Blue);

    fee_separator.width_policy.fixed(1);
    fee_separator.wallpaper = L'⏵';
    
    fee_input.width_policy.fixed(35);
    fee_input.brush.set_foreground(Color::Blue);
    fee_input.set_ghost_color(Color::Dark_gray);

    border.enable();
}

confirm_box::confirm_box()
{
    set_name("confirm box");
    focus_policy = Focus_policy::Direct;

    height_policy.fixed(3);

    confirm_text.width_policy.fixed(14);
    confirm_text.brush.set_foreground(Color::Blue);

    confirm_separator.width_policy.fixed(1);
    confirm_separator.wallpaper =  L'⏵';

    yes_button.width_policy.fixed(4);
    yes_button.brush.set_foreground(Color::Blue);

    no_button.width_policy.fixed(4);
    no_button.brush.set_foreground(Color::Blue);

    border.enable();
}

