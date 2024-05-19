#include "../headers/Block_5.h"

Block_5 :: Block_5(Base* ptr, string nm) : Base(ptr, nm) {};

void Block_5::signal(string& message) {
	cout << '\n' << "Signal from " << absolute_path();
	message += " (class: 5)";
}

void Block_5::handler(string message) {
	cout << '\n' << "Signal to " << absolute_path() << " Text: " << message;
}