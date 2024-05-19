#include "../headers/Block_4.h"

Block_4 :: Block_4(Base* ptr, string nm) : Base(ptr, nm) {};

void Block_4::signal(string& message) {
	cout << '\n' << "Signal from " << absolute_path();
	message += " (class: 4)";
}

void Block_4::handler(string message) {
	cout << '\n' << "Signal to " << absolute_path() << " Text: " << message;
}