#include "gui.hpp"
#include "pages.hpp"

#include <cppurses/cppurses.hpp>    
//#include <biji.hpp>  

//using namespace biji;

wallet_gui::wallet_gui()
{
    border.enable();
    set_name("wallet gui");
    wallet_menu.set_name("wallet menu");

    brush.set_foreground(Color::Blue);

    title.brush.set_foreground(Color::Blue);
    title.height_policy.preferred(3);
    title.border.enable(); 

    focus_policy = Focus_policy::Direct;
    
    if (Focus::focus_widget())
        spdlog::debug("focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("none");

    auto& esc_short = Shortcuts::add_shortcut(Key::Escape);
    esc_short.connect([this] { wallet_menu.goto_menu(); });
}

