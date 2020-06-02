#include <signals/signal.hpp>
#include <signals/slot.hpp>

#include <signals/signals.hpp>

#include "dark_menu_stack.hpp"

using namespace biji;

namespace {
const std::size_t menu_index{0u};
}  // namespace

namespace cppurses {

dark_menu_stack::dark_menu_stack(Glyph_string title)
    : d_menu{this->Stack::make_page<Dark_menu>(std::move(title))}
{
    this->Stack::set_active_page(menu_index);
    this->focus_policy = Focus_policy::Direct;
}

void dark_menu_stack::append_page(Glyph_string title, std::unique_ptr<Widget> widget)
{
    this->Stack::append_page(std::move(widget));
    this->connect_to_menu(std::move(title), this->Stack::size() - 1);
}

void dark_menu_stack::insert_page(Glyph_string title,
                             std::size_t index,
                             std::unique_ptr<Widget> widget)
{
    this->Stack::insert_page(index + 1, std::move(widget));
    this->connect_to_menu(std::move(title), index + 1);
}

void dark_menu_stack::delete_page(std::size_t index)
{
    this->remove_from_menu(index + 1);
    this->Stack::delete_page(index + 1);
}

std::unique_ptr<Widget> dark_menu_stack::remove_page(std::size_t index)
{
    this->remove_from_menu(index + 1);
    return this->Stack::remove_page(index + 1);
}

void dark_menu_stack::clear()
{
    this->goto_menu();
    for (auto i = 1u; i < this->Stack::size(); ++i) {
        this->children.get()[i]->close();
    }
}

void dark_menu_stack::goto_menu() { this->Stack::set_active_page(menu_index); }

void dark_menu_stack::set_active_page(std::size_t index)
{
    this->Stack::set_active_page(index + 1);
}

bool dark_menu_stack::focus_in_event()
{
    Focus::set_focus_to(d_menu);
    return Stack::focus_in_event();
}

void dark_menu_stack::remove_from_menu(std::size_t index)
{
    d_menu.remove_item(index - 1);
    if (this->Stack::active_page_index() == index)
        this->Stack::set_active_page(menu_index);
}

void dark_menu_stack::connect_to_menu(Glyph_string title, std::size_t index)
{
    auto& signal = d_menu.insert_item(std::move(title), index - 1);
    signal.connect(slot::set_active_page(*this, index));
}
}  // namespace cppurses
