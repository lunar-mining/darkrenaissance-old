#ifndef DARK_MENU_HPP
#define DARK_MENU_HPP
#include <cstddef>
#include <functional>
#include <vector>

#include <biji.hpp>   
#include <signals/slot.hpp>
#include <cppurses/cppurses.hpp>

using namespace biji;

namespace cppurses {
class Glyph_string;
class Push_button;
struct Label;

class Dark_menu
    : public layout::Horizontal
{
   public:

    Dark_menu(Glyph_string title_text);

    sig::Signal<void()>& append_item(Glyph_string label);

    sig::Signal<void()>& insert_item(Glyph_string label, std::size_t index);

    void remove_item(std::size_t index);

    void select_item(std::size_t index);

    void select_up(std::size_t n = 1);

    void select_down(std::size_t n = 1);

    std::size_t size() const { return items_.size(); }

    void set_selected_attribute(const Attribute& attr);

    void hide_title();

    void show_title();

    void hide_line_break();

    void show_line_break();

    void enable(bool enable                    = true,
                bool post_child_polished_event = true) override;

    Label& title;

    Fixed_height& line_break{this->make_child<Fixed_height>(1)};

   protected:
    bool key_press_event(const Key::State& keyboard) override;

    bool mouse_press_event(const Mouse::State& mouse) override;

    bool mouse_press_event_filter(Widget& /* receiver */,
                                  const Mouse::State& mouse) override;

   private:
    struct Dark_menu_item {
        explicit Dark_menu_item(Push_button& ref) : button{ref} {};
        std::reference_wrapper<Push_button> button;
        sig::Signal<void()> selected;
    };
    std::vector<Dark_menu_item> items_;
    std::size_t selected_index_{0};
    Attribute selected_attr_{Attribute::Inverse};

    bool title_enabled_{true};
    bool line_break_enabled_{true};

    void send_selected_signal();
};

namespace slot {

sig::Slot<void(std::size_t)> select_up(Dark_menu& m);
sig::Slot<void()> select_up(Dark_menu& m, std::size_t n);

sig::Slot<void(std::size_t)> select_down(Dark_menu& m);
sig::Slot<void()> select_down(Dark_menu& m, std::size_t n);

sig::Slot<void(std::size_t)> select_item(Dark_menu& m);
sig::Slot<void()> select_item(Dark_menu& m, std::size_t index);

}  // namespace slot
}  // namespace cppurses
#endif  // DARK_MENU_HPP
