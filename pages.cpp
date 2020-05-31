#include "pages.hpp"
#include "gui.hpp"
#include <cppurses/cppurses.hpp>
#include <biji.hpp>     

using namespace biji;

landing_page::landing_page()
{
    text.set_alignment(Alignment::Center);
    text.brush.set_foreground(Color::Dark_blue);
}

send_page::send_page()
{
}

receive_page::receive_page()
{
    text.set_alignment(Alignment::Center);
}

balance_page::balance_page()
{
    text.set_alignment(Alignment::Center);
} 

history_page::history_page()
{
    text.set_alignment(Alignment::Center);
}                               

