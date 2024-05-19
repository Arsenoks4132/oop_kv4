#include "../headers/Block_6.h"

Block_6 ::Block_6(Base *ptr, string nm) : Base(ptr, nm){};

void Block_6::signal(string &message)
{
	cout << '\n'
		 << "Signal from " << absolute_path();
	message += " (class: 6)";
}

void Block_6::handler(string message)
{
	cout << '\n'
		 << "Signal to " << absolute_path() << " Text: " << message;
}