default: pages.o gui.o main.o send_widget.o boxes.o dark_menu.o dark_menu_stack.o
	g++ *.o -lcppurses -lncursesw -pthread

# $(shell pkg-config --libs biji) 

pages.o: pages.hpp pages.cpp
	g++ -c pages.cpp

# $(shell pkg-config --cflags biji) 

main.o: main.cpp
	g++ -c main.cpp  

# $(shell pkg-config --cflags biji)

gui.o: gui.hpp gui.cpp
	g++ -c gui.cpp 

# $(shell pkg-config --cflags biji)

send_widget.o: send_widget.hpp send_widget.cpp 
	g++ -c send_widget.cpp

# $(shell pkg-config --cflags biji) 

boxes.o: boxes.hpp boxes.cpp
	g++ -c boxes.cpp 

# $(shell pkg-config --cflags biji) 

dark_menu.o: dark_menu.hpp dark_menu.cpp
	g++ -c dark_menu.cpp

# $(shell pkg-config --cflags biji)

dark_menu_stack.o: dark_menu_stack.hpp dark_menu_stack.cpp
	g++ -c dark_menu_stack.cpp

# $(shell pkg-config --cflags biji)

#verify_button.o: verify_button.hpp verify_button.cpp
#	g++ -c verify_button.cpp $(shell pkg-config --cflags biji)
