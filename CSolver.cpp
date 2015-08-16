#include <stdio.h>
#include <set>
#include "CSolver.h"

using namespace std; 

CSolver::CSolver()
{
	sudokuBoard = new CGameBoard();
	int errorCode = loadBoard();
	
	if (errorCode != 0)
	{
		perror("CSolver - error: Error Occured during loading test board!\n");
	}

	return;
}	

bool CSolver::checkRow(int row)
{
	int numbersAtRow[BOARDSIZE];
	CGameBoardElement* pGameBoardElem_temp = NULL;
	std::set<int> checkSet;

	// Row must range from 0 to 8. Note that the row index starts from 0, not 1
	if ( (row < 0) || (row > 8) )
	{
		perror("CSolver - Warning: row is out of bound\n");
		return false;
	}

	// Copying over the row we want to evaluate
	for (int col = 0; col < BOARDSIZE; col++)
	{
		pGameBoardElem_temp = (*sudokuBoard).get_element(row, col);
		numbersAtRow[col] = (*pGameBoardElem_temp).get_number();
	}

	// Checking for correctness (Array must contain all numbers in range of 1-9 without any repeats)
	// Will be using Set. Since elements of a set have to be unique, size of elements after insertion should be 9.
	for (int i = 0; i < BOARDSIZE; i++ )
	{
		if (numbersAtRow[i] < 0 || numbersAtRow[i] > 9)
		{
			// Board contains out of bound numbers
			perror("CSolver - Error: Board has invalid number\n");
			return false;

		}
		else if (numbersAtRow[i] == 0)
		{
			// Board has empty fields
			return false;
		}
		else
		{
			checkSet.insert(numbersAtRow[i]);
		}
	}

	if (checkSet.size() == 9)
	{
		return true;
	}
	else
	{
		return false;
	}


}

bool CSolver::checkCol(int col)
{
	int numbersAtCol[BOARDSIZE];
	CGameBoardElement* pGameBoardElem_temp = NULL;
	std::set<int> checkSet;

	// Column must range from 0 to 8. Note that the column index starts from 0, not 1
	if ( (col < 0) || (col > 8) )
	{
		perror("CSolver - Warning: col is out of bound\n");
		return -1;
	}

	// Copying over the column we want to evaluate
	for (int row = 0; row < BOARDSIZE;  row++)
	{
		pGameBoardElem_temp = (*sudokuBoard).get_element(row, col);
		numbersAtCol[row] = (*pGameBoardElem_temp).get_number();
	}

	// Checking for correctness (Array must contain all numbers in range of 1-9 without any repeats)
	// Will be using Set. Since elements of a set have to be unique, size of elements after insertion should be 9.
	for (int i = 0; i < BOARDSIZE; i++ )
	{
		if (numbersAtCol[i] < 0 || numbersAtCol[i] > 9)
		{
			// Board contains out of bound numbers
			perror("CSolver - Error: Board has invalid number\n");
			return false;

		}
		else if (numbersAtCol[i] == 0)
		{
			// Board has empty fields
			return false;
		}
		else
		{
			checkSet.insert(numbersAtCol[i]);
		}
	}

	if (checkSet.size() == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CSolver::checkSquare(int squareNum)
{
	/* squareNum 0 -->  0 <= row <= 2 & 0 <= col <= 2
	 * squareNum 1 -->  0 <= row <= 2 & 3 <= col <= 5
	 * squareNum 2 -->  0 <= row <= 2 & 6 <= col <= 8

	 * squareNum 3 -->  3 <= row <= 5 & 0 <= col <= 2
	 * squareNum 4 -->  3 <= row <= 5 & 3 <= col <= 5
	 * squareNum 5 -->  3 <= row <= 5 & 6 <= col <= 8

	 * squareNum 6 -->  6 <= row <= 8 & 0 <= col <= 2
	 * squareNum 7 -->  6 <= row <= 8 & 3 <= col <= 5
	 * squareNum 8 -->  6 <= row <= 8 & 6 <= col <= 8
	 */

	int numbersAtSquare[BOARDSIZE];
	CGameBoardElement* pGameBoardElem_temp = NULL;
	std::set<int> checkSet;

	int row, col;
	int rowScale, colScale;
	int index = 0;

	// Sanity Check
	 if (squareNum < 0 || squareNum > 8)
	 {
	 	perror("CSolver - Error: square number out of bound\n");
	 	return false;
	 }

	 // scale setting for col
	 if (squareNum == 0 || squareNum == 3 || squareNum == 6)
	 {
	 	colScale = 0;
	 }
	 else if (squareNum == 1 || squareNum == 4 || squareNum == 7)
	 {
	 	colScale = 1;
	 }
	 else if (squareNum == 2 || squareNum == 5 || squareNum == 8)
	 {
	 	colScale = 2;
	 }

	 // Scale Setting for row
	 if (squareNum == 0 || squareNum == 1 || squareNum == 2)
	 {
	 	rowScale = 0;
	 }
	 else if (squareNum == 3 || squareNum == 4 || squareNum == 5)
	 {
	 	rowScale = 1;
	 }
	 else if (squareNum == 6 || squareNum == 7 || squareNum == 8)
	 {
	 	rowScale = 2;
	 }

	// copy over the integers stored in the elements
	for (row = 0 ; row < 3 ; row++)
	{
		for (col = 0 ; col < 3; col++)
		{
			pGameBoardElem_temp = (*sudokuBoard).get_element(row + 3*rowScale, col + 3*colScale);
			numbersAtSquare[index] = (*pGameBoardElem_temp).get_number();
			index++;
		}
	}

	// Debug
	/*
	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout<<numbersAtSquare[i]<< " ";
	}
	cout<<endl;
	*/

	// Checking for correctness using set
	for (int i = 0; i < BOARDSIZE; i++ )
	{
		if (numbersAtSquare[i] < 0 || numbersAtSquare[i] > 9)
		{
			// Board contains out of bound numbers
			perror("CSolver - Error: Board has invalid number\n");
			return false;

		}
		else if (numbersAtSquare[i] == 0)
		{
			// Board has empty fields
			return false;
		}
		else
		{
			checkSet.insert(numbersAtSquare[i]);
		}
	}

	if (checkSet.size() == 9)
	{
		return true;
	}
	else
	{
		return false;
	}

	 	

}

int CSolver::loadBoard ()
{
	ifstream sampleBoard ("boardSample2_ans.txt", std::ifstream::in);
	// ifstream sampleBoard ("boardSample1.txt", std::ifstream::in);
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
		// cout << data << endl; // debug

		// if the read character is a number btwn 0-9, put it into the board
		if (data >= 0 && data <= 9)
		{
			// Since data is valid entry (number from 0 to 9) with 0 indicating empty field, increment entryCounter
			entryCounter++;

			pNewElement = new CGameBoardElement(data);
			(*sudokuBoard).set_element(rowCounter, colCounter, pNewElement);
			// cout << "inserted " << data << "at " << rowCounter << ", " << colCounter << endl; // debug
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
		perror("CSolver - error: testboard contains less entries than expected!\n");
		return -1;
	}
	
	return 0;
}


void CSolver::printBoard () 
{
	int row, col;

	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			cout << (*sudokuBoard).get_element(row,col)->get_number() << " ";
		}

		cout << endl;
	}

	return;

}