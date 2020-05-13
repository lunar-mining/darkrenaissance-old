#ifndef DARK_WALLET_GUI_HPP
#define DARK_WALLET_GUI_HPP

#include "pages.hpp"
#include <cppurses/cppurses.hpp>
#include <biji.hpp>     

using namespace biji;

class wallet_gui
  : public layout::Vertical
{
public:
    wallet_gui();

    Text_display& title{make_child<Text_display>
        ("D A R K  R E N A I S S A N C E  W A L L E T")};    

    layout::Horizontal& buttons{make_child<layout::Horizontal>()};

    Push_button& send_button{buttons.make_child<Push_button>("send")};     

    Push_button& receive_button{buttons.make_child<Push_button>("receive")};  
    
    Push_button& balance_button{buttons.make_child<Push_button>("balance")}; 

    Push_button& history_button{buttons.make_child<Push_button>("history")}; 

    layout::Stack& pages_stack{make_child<layout::Stack>()};

    landing_page& landing{pages_stack.make_page<landing_page>()};

    send_page& send{pages_stack.make_page<send_page>()};

    receive_page& receive{pages_stack.make_page<receive_page>()};   

    balance_page& balance{pages_stack.make_page<balance_page>()}; 

    history_page& history{pages_stack.make_page<history_page>()}; 

    /// Arrow keys up/down will select up/down, Enter key will send Signal.
    bool key_press_event(const Key::State& keyboard);  /*

    /// Selects up/down on scroll wheel.
    bool mouse_press_event(const Mouse::State& mouse) override;

    /// Selects up/down on scroll wheel.
    bool mouse_press_event_filter(Widget& ,
                                  const Mouse::State& mouse) override;*/     
};    

#endif // DARK_WALLET_GUI_HPP
