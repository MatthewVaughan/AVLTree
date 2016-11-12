// CS2420 Programming Project #07
// Copyright 2014, Utah Valley University
//Author: Matthew Vaughan
// Date last modified: Oct 2016
// Header file for main - constants and function prologues
// =================================================

/*I Matthew Vaughan have not used any code other than my own(or that in the textbook)
for this project.I also have not used any function or data - structure from
the Standard - Template Library.I understand that any violation of this
disclaimer will result in a 0 for the project.*/

#include "AVL.h"


void print_menu();
char get_user_command();
int get_number();

int main()
{
	AVL test; // A list that we’ll perform tests on
	char choice;   // A command character entered by the user
	int input;

	cout << "I have initialized an empty Binary Tree of real numbers." << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case 'S': cout << "Size is " << test.getSize() << '.' << endl;
			break;
		case 'I': test.Insert(get_number());
			break;
		case 'P': test.PrintTree();
			break;
		case 'X':test.~AVL();
			break;
		case 'Q':
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " S   Print the result from the size( ) function" << endl;
	cout << " P   Print the tree" << endl;
	cout << " I   Insert a new number with the insert(...)" << endl;
	cout << " X   Erase the Tree" << endl;
	cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter an integer: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}