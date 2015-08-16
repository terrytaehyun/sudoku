#include <iostream>
#include "CSolver.h"
#include "CGameBoardElement.h"
#include "CGameBoard.h"

using namespace std;

// int loadTestBoard(CGameBoard* pGameBord);
// void printBoard(CGameBoard* pGameBord);

int main()
{
	CSolver sudoku;
	bool isCorrect;

	sudoku.printBoard();
	for(int row = 0; row < BOARDSIZE; row++)
	{
		isCorrect = sudoku.checkRow(row);
		if (isCorrect)
		{
			cout << "Entries at row: " << row << " is Correct!" << endl;
		}
		else
		{
			cout << "Entries at row: " << row << " is Incorrect!" << endl;	
		}
	}

	for (int col = 0; col < BOARDSIZE; col++)
	{
		isCorrect = sudoku.checkRow(col);
		if (isCorrect)
		{
			cout << "Entries at col: " << col << " is Correct!" << endl;
		}
		else
		{
			cout << "Entries at col: " << col << " is Incorrect!" << endl;	
		}
	}

	for (int squareNum = 0; squareNum < BOARDSIZE; squareNum++)
	{
		isCorrect = sudoku.checkSquare(squareNum);
		if (isCorrect)
		{
			cout << "Entries at squareNum: " << squareNum << " is Correct!" << endl;
		}
		else
		{
			cout << "Entries at squareNum: " << squareNum << " is Incorrect!" << endl;	
		}
	}

	// For holding the screen
	char ch;
	cin.get(ch);

	return 0;
}




// int loadTestBoard (CGameBoard* pGameBord)
// {
// 	ifstream sampleBoard ("boardSample2_ans.txt", std::ifstream::in);
// 	// ifstream sampleBoard ("boardSample1.txt", std::ifstream::in);
// 	CGameBoardElement* pNewElement;

// 	int data;

// 	int entryCounter = 0;
// 	int rowCounter = 0;
// 	int colCounter = 0;

// 	// eof() checks whether end of file is set
// 	// entryCounter < 81 ensures any extra entries are truncated
// 	while (!sampleBoard.eof() && entryCounter < 81 ) 
// 	{
// 		// read one character at a time and convert
// 		data = sampleBoard.get() - 48; // subtract 48 for taking consideration of ascii code number
// 		// cout << data << endl; // debug

// 		// if the read character is a number btwn 0-9, put it into the board
// 		if (data >= 0 && data <= 9)
// 		{
// 			// Since data is valid entry (number from 0 to 9) with 0 indicating empty field, increment entryCounter
// 			entryCounter++;

// 			pNewElement = new CGameBoardElement(data);
// 			(*pGameBord).set_element(rowCounter, colCounter, pNewElement);
// 			// cout << "inserted " << data << "at " << rowCounter << ", " << colCounter << endl; // debug
//  			// Increment the row and col counter appropriately
// 			colCounter++;
// 			if (colCounter > 8) // column starts from 0 and ends at 8
// 			{
// 				rowCounter++;
// 				colCounter = 0;
// 			}
// 		}
// 	}

// 	// If file contains less entry than expected raise error and exit
// 	if (entryCounter < 81 )
// 	{
// 		cout<<"entryCounter: "<<entryCounter<<endl;
// 		perror("Sudoku - error: testboard contains less entries than expected!\n");
// 		return -1;
// 	}
	
// 	return 0;
// }

// void printBoard (CGameBoard* pGameBord) 
// {
// 	int row, col;

// 	for (row = 0; row < 9; row++)
// 	{
// 		for (col = 0; col < 9; col++)
// 		{
// 			cout << (*pGameBord).get_element(row,col)->get_number() << " ";
// 		}

// 		cout << endl;
// 	}

// }