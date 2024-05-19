#include "../headers/Block_3.h"

Block_3 ::Block_3(Base *ptr, string nm) : Base(ptr, nm){};

void Block_3::signal(string &message)
{
	cout << '\n'
		 << "Signal from " << absolute_path();
	message += " (class: 3)";
}

void Block_3::handler(string message)
{
	cout << '\n'
		 << "Signal to " << absolute_path() << " Text: " << message;
}