#include <fstream>
#include <iostream>
#include <signals/signal.hpp>
#include <cppurses/cppurses.hpp>
//#include <biji.hpp>   
#include <spdlog/spdlog.h>

#include "send_stack.hpp"

using namespace cppurses;
//using namespace biji;

const std::size_t front_page{0};
const std::size_t confirm_page{1};
const std::size_t error_page{2};
const std::size_t sending_page{3};

// TODO: need another confirm_popup that flags if entry data fails tests
// TODO: inverse attributes on focus

send_stack::send_stack()
  : confirm{make_page<confirm_popup>(*this)},
    error{make_page<error_popup>(*this)},
    sending{make_page<sending_popup>(*this)}
{
    set_active_page(front_page);
    set_name("send stack");
    give_focus_on_change(true);

    send_menu.focus_policy = Focus_policy::Direct;
    send_menu.set_name("menu layout");

    enter_address.set_name("address box");
    enter_address.focus_policy = Focus_policy::Direct;

    enter_amount.set_name("amount box");
    enter_amount.focus_policy = Focus_policy::Direct;

    enter_fee.set_name("fee box");
    enter_fee.focus_policy = Focus_policy::Direct;

    enter_button.set_name("button box");
    enter_button.focus_policy = Focus_policy::Direct;
    enter_button.brush.set_background(Color::Black);
    enter_button.brush.set_foreground(Color::Blue);  
    enter_button.border.enable();
    enter_button.height_policy.expanding(3);


    // focus debugger
   if (Focus::focus_widget())
        spdlog::debug("Focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("None"); 
 
    // focus check on click
    /*enter_button.clicked.connect(
    [this]
    {
        set_active_page(confirm_page);
        spdlog::debug("Just set to confirm_page");
        confirm.execute();
        spdlog::debug("execute function called");
    }); */ // has to be deprecated because .clicked only works for mouse click

 //   if (Focus::focus_widget() == enter_button)
        //set_selected_attribute();
        
};                                     


/*bool send_stack::key_press_event(const Key::State& keyboard)
{
    spdlog::debug("Key press function called");
    if (keyboard.key == Key::Arrow_left) {
        spdlog::debug("Left arrow pushed");
    } else if (keyboard.key == Key::Arrow_right) {
        spdlog::debug("Right arrow pushed");
    } else if (keyboard.key == Key::Arrow_up) {
        spdlog::debug("Up arrow pushed");
    } else if (keyboard.key == Key::Arrow_down) {
        spdlog::debug("Down arrow pushed");
    } else if (keyboard.key == Key::Enter) {
        spdlog::debug("Send stack enter pushed");
        set_active_page(confirm_page);
        spdlog::debug("confirm page set");
        //confirm_page.execute();
    }
    return Widget::key_press_event(keyboard); 
};*/

confirm_popup::confirm_popup(send_stack& send)
  : send_w(send)
{
   if (Focus::focus_widget())
        spdlog::debug("Focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("None"); 

    set_name("confirm popup");
    focus_policy = Focus_policy::Direct;

    input_echo.border.enable();
    input_echo.height_policy.expanding(7);
    input_echo.width_policy.expanding(35);

    buttons.no_button.clicked.connect(
    [this]()
    {
        send_w.set_active_page(front_page);
    });

    buttons.yes_button.clicked.connect(
    [this]()
    {
        send_w.set_active_page(sending_page);
    });
}

// confirm page key presses happen here
bool confirm_popup::key_press_event(const Key::State& keyboard) {
    spdlog::debug("Key press function called");
    if (keyboard.key == Key::Arrow_left) {
        spdlog::debug("Left arrow pushed");
    } else if (keyboard.key == Key::Arrow_right) {
        spdlog::debug("Right arrow pushed");
    } else if (keyboard.key == Key::Arrow_up) {
        spdlog::debug("Up arrow pushed");
    } else if (keyboard.key == Key::Arrow_down) {
        spdlog::debug("Down arrow pushed");
    } else if (keyboard.key == Key::Enter) {
        spdlog::debug("Confirm page enter pushed");
        send_w.set_active_page(sending_page);
        spdlog::debug("active page set");
        execute();
    }
    return Widget::key_press_event(keyboard);
}

void confirm_popup::execute()
{
   if (Focus::focus_widget())
        spdlog::debug("Focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("None"); 

    Glyph_string input_data = "You entered:\n" +
        send_w.enter_address.address_input.contents().str() + "\n" +
        send_w.enter_fee.fee_input.contents().str() + "\n" +
        send_w.enter_amount.amount_input.contents().str();

    input_echo.set_contents(input_data);
}

void confirm_popup::build_transaction()
{
    // builds
}

void confirm_popup::broadcast()
{
    // broadcasts
}

error_popup::error_popup(send_stack& send)
  : send_w(send)
{
}

sending_popup::sending_popup(send_stack& send)
  : send_w(send)
{

   if (Focus::focus_widget())
        spdlog::debug("Focus is: {}", Focus::focus_widget()->name());
    else
        spdlog::debug("None"); 
}

/*void send_stack::select_up(std::size_t n)
{
    const auto new_index = selected_index_ > n ? selected_index_ - n : 0;
    this->select_item(new_index);
}

void send_stack::select_down(std::size_t n)
{
    this->select_item(selected_index_ + n);
}

//TODO: add debugs when buttons are called
void send_stack::select_item(std::size_t index)
{
    if (items_.empty())
    {
        return;
    }
    auto& previous_btn = items_[selected_index_].button.get();
    previous_btn.brush.remove_attributes(selected_attr_);
    previous_btn.update();

    selected_index_ = index >= items_.size() ? items_.size() - 1 : index;

    auto& current_btn = items_[selected_index_].button.get();
    current_btn.brush.add_attributes(selected_attr_);
    current_btn.update();
}

void send_stack::set_selected_attribute(const Attribute& attr)
{
    auto& selected_btn = items_[selected_index_].button.get();
    selected_btn.brush.remove_attributes(selected_attr_);
    selected_attr_ = attr;
    selected_btn.brush.add_attributes(selected_attr_);
    selected_btn.update();
} 

sig::Slot<void(std::size_t)> select_up(send_stack& m)
{
    sig::Slot<void(std::size_t)> slot{[&m](auto n) { m.select_up(n); }};
    slot.track(m.destroyed);
    return slot;
}

sig::Slot<void()> select_up(send_stack& m, std::size_t n)
{
    sig::Slot<void()> slot{[&m, n] { m.select_up(n); }};
    slot.track(m.destroyed);
    return slot;
}

sig::Slot<void(std::size_t)> select_down(send_stack& m)
{
    sig::Slot<void(std::size_t)> slot{[&m](auto n) { m.select_down(n); }};
    slot.track(m.destroyed);
    return slot;
}

sig::Slot<void()> select_down(send_stack& m, std::size_t n)
{
    sig::Slot<void()> slot{[&m, n] { m.select_down(n); }};
    slot.track(m.destroyed);
    return slot;
}

sig::Slot<void(std::size_t)> select_item(send_stack& m)
{
    sig::Slot<void(std::size_t)> slot{
        [&m](auto index) { m.select_item(index); }};
    slot.track(m.destroyed);
    return slot;
}

sig::Slot<void()> select_item(send_stack& m, std::size_t index)
{
    sig::Slot<void()> slot{[&m, index] { m.select_item(index); }};
    slot.track(m.destroyed);
    return slot;
}*/
