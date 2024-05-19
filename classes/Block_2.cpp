#include "../headers/Block_2.h"

Block_2 :: Block_2(Base* ptr, string nm) : Base(ptr, nm) {};

void Block_2::signal(string& message) {
	cout << '\n' << "Signal from " << absolute_path();
	message += " (class: 2)";
}

void Block_2::handler(string message) {
	cout << '\n' << "Signal to " << absolute_path() << " Text: " << message;
}