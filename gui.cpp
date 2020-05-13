#include "gui.hpp"
#include "pages.hpp"

#include <cppurses/cppurses.hpp>    
#include <biji.hpp>  

using namespace biji;

wallet_gui::wallet_gui()
{
 //   title.brush.set_background(Color::Blue);
    title.brush.set_foreground(Color::Blue);
    title.set_alignment(Alignment::Center);  
    title.height_policy.fixed(1);
    //title.border.enable(); 

    //send_button.brush.set_background(Color::Blue);
    send_button.brush.set_foreground(Color::Blue);
    send_button.height_policy.fixed(3);
    send_button.border.enable();

    //receive_button.brush.set_background(Color::Blue);
    receive_button.brush.set_foreground(Color::Blue);
    receive_button.height_policy.fixed(3);
    receive_button.border.enable();

    //balance_button.brush.set_background(Color::Blue);
    balance_button.brush.set_foreground(Color::Blue);
    balance_button.height_policy.fixed(3);
    balance_button.border.enable();

    //history_button.brush.set_background(Color::Blue);
    history_button.brush.set_foreground(Color::Blue);
    history_button.height_policy.fixed(3);    
    history_button.border.enable();

    focus_policy = Focus_policy::Tab;
//    enable_tab_focus();
    Focus::set_focus_to(*this);
   // set_selected_attribute(Attribute::Inverse);

    // defines pages

    pages_stack.set_active_page(0);
//    pages_stack.height_policy.fixed(10);
    pages_stack.give_focus_on_change(true);

    send_button.clicked.connect(slot::set_active_page(pages_stack, 1));
    receive_button.clicked.connect(slot::set_active_page(pages_stack, 2));
    balance_button.clicked.connect(slot::set_active_page(pages_stack, 3));
    history_button.clicked.connect(slot::set_active_page(pages_stack, 4));
}

bool wallet_gui::key_press_event(const Key::State& keyboard)
{  
    if (keyboard.key == Key::Arrow_down || keyboard.key == Key::j) {slot::set_active_page(pages_stack, 1);
    } else if (keyboard.key == Key::Arrow_up || keyboard.key == Key::k) {slot::set_active_page(pages_stack, 1);
    } else if (keyboard.key == Key::Enter) {slot::set_active_page(pages_stack, 1)();
    }
    return true; 
}   /*

bool Menu::mouse_press_event(const Mouse::State& mouse) {
    if (mouse.button == Mouse::Button::ScrollUp) {
        this->select_up();
    } else if (mouse.button == Mouse::Button::ScrollDown) {
        this->select_down();
    }
    return layout::Vertical::mouse_press_event(mouse);
}

bool Menu::mouse_press_event_filter(Widget&  receiver ,
                                    const Mouse::State& mouse) {
    if (mouse.button == Mouse::Button::ScrollUp) {
        this->select_up();
        return true;
    } else if (mouse.button == Mouse::Button::ScrollDown) {
        this->select_down();
        return true;
    }
    return false;  
}                 */                 
