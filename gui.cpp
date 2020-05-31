#include "gui.hpp"
#include "pages.hpp"

#include <cppurses/cppurses.hpp>    
#include <biji.hpp>  

using namespace biji;

wallet_gui::wallet_gui()
{
    border.enable();

    brush.set_foreground(Color::Blue);

    title.brush.set_foreground(Color::Blue);
    title.height_policy.preferred(3);
    title.border.enable(); 

    focus_policy = Focus_policy::Direct;

    auto& esc_short = Shortcuts::add_shortcut(Key::Escape);
    esc_short.connect([this] { wallet_menu.goto_menu(); });
}

