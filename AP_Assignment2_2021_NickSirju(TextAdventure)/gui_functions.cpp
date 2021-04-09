#include "gui_functions.h"


//Problems with gui_functions
//Added std::

const string gui::game_menu_title(const string title)
{
	stringstream ss;

	ss << "= " << title << " ="
		<< "\n"
		<< "\n";

	return ss.str();
}

const string gui::game_menu_divider(const unsigned amount, const char symbol)
{
	stringstream ss;

	ss << string(amount, symbol)
		<< "\n"
		<< "\n";

	return ss.str();
}

const string gui::game_menu_item(const unsigned index, const std::string text)
{
	stringstream ss;

	ss << "- " << "(" << index << ")" << text
		<< "\n";

	return ss.str();
}



