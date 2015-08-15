#include <iostream>
#include <fstream>  
#include "CGameBoardElement.h"
#include "CGameBoard.h"

using namespace std;

int loadTestBoard (CGameBoard* pGameBord)
{
	ifstream sampleBoard ("boardSample1.txt", std::ifstream::in);
	CGameBoardElement* pNewElement;

	int data;

	int entryCounter = 0;
	int rowCounter = 0;
	int colCounter = 0;

	// eof() checks whether end of file is set
	// entryCounter < 81 ensures any extra entries are truncated
	while (!sampleBoard.eof() && entryCounter < 81 ) 
	{
		// read one character at a time and convert
		data = sampleBoard.get() - 48; // subtract 48 for taking consideration of ascii code number
		cout << data << endl;
		// if the read character is a number btwn 0-9, put it into the board
		if (data >= 0 && data <= 9)
		{
			// Since data is valid entry (number from 0 to 9) with 0 indicating empty field, increment entryCounter
			entryCounter++;

			pNewElement = new CGameBoardElement(data);
			(*pGameBord).set_element(rowCounter, colCounter, pNewElement);
			cout << "inserted " << data << "at " << rowCounter << ", " << colCounter << endl;
 			// Increment the row and col counter appropriately
			colCounter++;
			if (colCounter > 8) // column starts from 0 and ends at 8
			{
				rowCounter++;
				colCounter = 0;
			}
		}
	}

	// If file contains less entry than expected raise error and exit
	if (entryCounter < 81 )
	{
		cout<<"entryCounter: "<<entryCounter<<endl;
		perror("Sudoku - error: testboard contains less entries than expected!\n");
		return -1;
	}
	
	return 0;
}

void printBoard (CGameBoard* pGameBord) 
{
	int row, col;

	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			cout << (*pGameBord).get_element(row,col)->get_number() << " ";
		}

		cout << endl;
	}

}

int main()
{
	CGameBoard* pGameBord;
	pGameBord = new CGameBoard();

	CGameBoardElement newElement;

	int errorCode = 0;

	// Loading testing board
	errorCode = loadTestBoard(pGameBord);

	if (errorCode != 0)
	{
		perror("Sudoku - error: Error Occured during loading test board!\n");
		return -1;
	}

	// newElement.set_number(5);

	// testing.set_element(1, 1, newElement);

	printBoard(pGameBord);
	cout << "element at 0, 0: " << (*pGameBord).get_element(0,0)->get_number() << endl;
	cout << "element at 1, 1: " << (*pGameBord).get_element(1,1)->get_number() << endl;
	
	// CGameBoardElement anotherElement;
	// anotherElement.set_number(7);
	// anotherElement.set_state(Found);
	// testing.set_element(1, 1, anotherElement);

	// cout << "element at 1, 1: " << testing.get_element(1,1).get_number() << endl;
	// cout << "element at 1, 1: " << testing.get_element(1,1).get_state() << endl;

	// For holding the screen
	char ch;
	cin.get(ch);

	return 0;
}
