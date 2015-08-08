#include "CGameBoard.h"

Class CSolver
{

	private:
		CGameBoard sudokuBoard;

	public:
		CSolver();
		bool checkRow(int row);
		bool checkCol(int col);
		bool checkSquare(int squareNum);

};