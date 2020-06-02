#ifndef DARK_MENU_STACK_HPP
#define DARK_MENU_STACK_HPP

#include <cstddef>
#include <memory>
#include <utility>

#include "dark_menu.hpp"

namespace cppurses {
//class Widget;
//class dark_menu;

class dark_menu_stack
    : public layout::Stack
{
    Dark_menu& d_menu;

   public:
    dark_menu_stack(Glyph_string title = "");

    template <typename T, typename... Args>
    T& make_page(Glyph_string title, Args&&... args);

    void append_page(Glyph_string title, std::unique_ptr<Widget> widget);

    void insert_page(Glyph_string title,
                     std::size_t index,
                     std::unique_ptr<Widget> widget);

    void delete_page(std::size_t index);

    std::unique_ptr<Widget> remove_page(std::size_t index);

    void clear();

    std::size_t size() const { return this->Stack::size() - 1; }

    Dark_menu& dark_menu()
    {
        return d_menu;
    }

    const Dark_menu& dark_menu() const
    {
        return d_menu;
    }

    void goto_menu();

    void set_active_page(std::size_t index);

   private:
    void remove_from_menu(std::size_t index);

    void connect_to_menu(Glyph_string title, std::size_t index);

   protected:
    bool focus_in_event() override;
};

template <typename T, typename... Args>
T& dark_menu_stack::make_page(Glyph_string title, Args&&... args) {
    auto& ret = this->Stack::make_page<T>(std::forward<Args>(args)...);
    connect_to_menu(std::move(title), this->Stack::size() - 1);
    return ret;
}
}  // namespace cppurses
#endif  // DARK_MENU_STACK_HPP
