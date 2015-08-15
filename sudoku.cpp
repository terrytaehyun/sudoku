#include <iostream>
#include "CGameBoardElement.h"
#include "CGameBoard.h"

using namespace std;
void loadTestBoard (CGameBoard* pGameBord)
{
	ifstream sampleBoard("boardSample1.txt");
	CGameBoardElement* pNewElement;

	int data;
	int rowCounter = 0;
	int colCounter = 0;

	while (!sampleBoard.eof()) // eof() checks whether end of file is set
	{
		// read one character at a time and convert
		// if the read character is a number btwn 0-9, put it into the board
		data = sampleBoard.read(readCharacter, 1) - '0'; // - '0' for changing char to int

		if (data >= 0 || data <= 9)
		{
			pNewElement = new CGameBoardElement(data);
			(*pGameBord).set_element(pNewElement);

			// Increment the row and col counter appropriately
			colCounter++;
			if (colCounter > 9) // column starts from 0 and ends at 8
			{
				rowCounter++;
				colCounter = 0;
			}
		}
	}
	
	return;
}

int main()
{
	CGameBoard* pGameBord;
	pGameBord = new CGameBoard();

	CGameBoardElement newElement;

	// Loading testing board
	loadTestBoard(pGameBord);

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