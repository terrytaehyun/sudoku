#include <stdio.h>
#include "CSolver.h"

CSolver::CSolver()
{

}

bool CSolver::checkRow(int row)
{
	int numbersAtRow[BOARDSIZE];

	// Row must range from 0 to 8. Note that the row index starts from 0, not 1
	if ( (row < 0) || (row > 8) )
	{
		perror("CSolver - Warning: row is out of bound");
		return -1;
	}

	// Copying over the row we want to evaluate
	for (int col = 0; col < BOARDSIZE; col++)
	{
		numbersAtRow[col] = sudokuBoard.get_element(row, col);
	}

	// Checking for correctness (Array must contain all numbers in range of 1-9 without any repeats)
	// Sort the array in ascending order and check if index+1 matches the content of the array at the index

}

bool CSolver::checkCol(int col)
{
	int numbersAtCol[BOARDSIZE];

	// Column must range from 0 to 8. Note that the column index starts from 0, not 1
	if ( (col < 0) || (col > 8) )
	{
		perror("CSolver - Warning: col is out of bound");
		return -1;
	}

	// Copying over the column we want to evaluate
	for (int row = 0; row < BOARDSIZE;  row++)
	{
		numbersAtCol[row] = sudokuBoard.get_element(row, col);
	}

	// Checking for correctness (Array must contain all numbers in range of 1-9 without any repeats)
	// Sort the array in ascending order and check if index+1 matches the content of the array at the index
}

bool CSolver::checkSquare(int squareNum)
{

}