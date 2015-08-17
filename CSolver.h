#include "CGameBoard.h"
#include <fstream>  
#include <iostream>

#ifndef CSOLVER_H
#define CSOLVER_H

class CSolver
{

	private:
		CGameBoard* sudokuBoard;

	public:
		CSolver();
		bool checkRow(int row);
		bool checkCol(int col);
		bool checkSquare(int squareNum);

		std::set<int> calculatePossibilities(int row, int col);

		int loadBoard();
		void printBoard();

};

#endif