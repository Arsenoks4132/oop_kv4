#include "../headers/TreeMaker.h"
#include "../headers/Block_2.h"
#include "../headers/Block_3.h"
#include "../headers/Block_4.h"
#include "../headers/Block_5.h"
#include "../headers/Block_6.h"
#include <iostream>

TreeMaker ::TreeMaker(TreeMaker *ptr, string nm) : Base(ptr, nm){};

void TreeMaker ::MakeTree()
{
	string tm_Name;
	cin >> tm_Name;
	if (!rename(tm_Name))
	{
		return;
	}
	string parent_name, child_name;
	int number;

	Base *parent;
	while (cin >> parent_name)
	{
		if (parent_name == "endtree")
		{
			break;
		}
		cin >> child_name >> number;

		parent = find_coord(parent_name);

		if (!parent)
		{
			cout << "Object tree\n";
			printTree();
			cout << "\nThe head object " << parent_name << " is not found";
			exit(1);
		}

		if (parent->getLeaf(child_name))
		{
			cout << parent_name << "     Dubbing the names of subordinate objects\n";
		}
		else
		{
			switch (number)
			{
			case 2:
				new Block_2(parent, child_name);
				break;
			case 3:
				new Block_3(parent, child_name);
				break;
			case 4:
				new Block_4(parent, child_name);
				break;
			case 5:
				new Block_5(parent, child_name);
				break;
			case 6:
				new Block_6(parent, child_name);
				break;
			}
		}
	}

	// KV_4_______________________
	string coord_one, coord_two;
	Base *obj_one;
	Base *obj_two;
	while (cin >> coord_one)
	{
		if (coord_one == "end_of_connections")
		{
			break;
		}
		cin >> coord_two;
		obj_one = find_coord(coord_one);
		obj_two = find_coord(coord_two);
		if (obj_one && obj_two)
		{
			obj_one->set_connect(SIGNAL_D(Base::signal), obj_two, HANDLER_D(Base::handler));
		}
	}
	// KV_4_______________________
};

int TreeMaker ::Start()
{
	cout << "Object tree\n";
	printTree();

	this->set_ready();

	string command, coord_one, coord_two, message;
	int ready;
	Base *obj_one;
	Base *obj_two;
	while (cin >> command)
	{
		if (command == "EMIT")
		{
			cin >> coord_one;
			getline(cin, message);
			obj_one = find_coord(coord_one);
			if (obj_one)
			{
				obj_one->emit_signal(SIGNAL_D(Base::signal), message);
			}
			else
			{
				cout << "Object " << coord_one << " not found" << '\n';
			}
		}
		else if (command == "SET_CONNECT")
		{
			cin >> coord_one >> coord_two;
			obj_one = find_coord(coord_one);
			obj_two = find_coord(coord_two);
			if (!obj_one)
			{
				cout << "Object " << coord_one << " not found" << '\n';
				continue;
			}
			if (!obj_two)
			{
				cout << "Handler object " << coord_two << " not found" << '\n';
			}
			obj_one->set_connect(SIGNAL_D(Base::signal), obj_two, HANDLER_D(Base::handler));
		}
		else if (command == "DELETE_CONNECT")
		{
			cin >> coord_one >> coord_two;
			obj_one = find_coord(coord_one);
			obj_two = find_coord(coord_two);
			if (!obj_one)
			{
				cout << "Object " << coord_one << " not found" << '\n';
				continue;
			}
			if (!obj_two)
			{
				cout << "Handler object " << coord_two << " not found" << '\n';
			}
			obj_one->delete_connect(SIGNAL_D(Base::signal), obj_two, HANDLER_D(Base::handler));
		}
		else if (command == "SET_CONDITION")
		{
			cin >> ready;
			obj_one = find_coord(coord_one);
			if (obj_one)
			{
				obj_one->set_state(ready);
			}
			else
			{
				cout << "Object " << coord_one << " not found" << '\n';
			}
		}
		else if (command == "END")
		{
			break;
		}
	}
	return 0;
};