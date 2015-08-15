#include "CGameBoard.h"

#ifndef CSOLVER_H
#define CSOLVER_H

class CSolver
{

	private:
		CGameBoard sudokuBoard;

	public:
		CSolver();
		bool checkRow(int row);
		bool checkCol(int col);
		bool checkSquare(int squareNum);

};

#endif