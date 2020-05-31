#ifndef DARK_WALLET_GUI_HPP
#define DARK_WALLET_GUI_HPP

#include "pages.hpp"
#include <cppurses/cppurses.hpp>
#include <biji.hpp>     

#include "dark_menu_stack.hpp"

using namespace biji;

class wallet_gui
  : public layout::Vertical
{
public:
    wallet_gui();

    Push_button& title{make_child<Push_button>
        ("D A R K  R E N A I S S A N C E  W A L L E T" )};    

    Menu_stack& wallet_menu{make_child<Menu_stack>(" ")};

    send_page& send{wallet_menu.make_page<send_page>("SEND")};

    receive_page& receive{wallet_menu.make_page<receive_page>("RECEIVE")};   

    balance_page& balance{wallet_menu.make_page<balance_page>("BALANCE")}; 

    history_page& history{wallet_menu.make_page<history_page>("HISTORY")}; 
};    


#endif // DARK_WALLET_GUI_HPP
