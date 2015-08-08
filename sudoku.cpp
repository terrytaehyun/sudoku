#include <iostream>
#include "CGameBoardElement.h"
#include "CGameBoard.h"

using namespace std;

int main()
{
	CGameBoard testing;
	CGameBoardElement newElement;

	newElement.set_number(5);

	testing.set_element(1, 1, newElement);

	cout << "element at 0, 0: " << testing.get_element(0,0).get_number() << endl;
	cout << "element at 1, 1: " << testing.get_element(1,1).get_number() << endl;
	
	CGameBoardElement anotherElement;
	anotherElement.set_number(7);
	anotherElement.set_state(Found);
	testing.set_element(1, 1, anotherElement);

	cout << "element at 1, 1: " << testing.get_element(1,1).get_number() << endl;
	cout << "element at 1, 1: " << testing.get_element(1,1).get_state() << endl;

	// For holding the screen
	char ch;
	cin.get(ch);

	return 0;
}