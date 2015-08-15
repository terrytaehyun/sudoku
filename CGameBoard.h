#include "CGameBoardElement.h"

#ifndef CGAMEBOARD_H
#define CGAMEBOARD_H

#define BOARDSIZE 9

class CGameBoard 
{
	private:
		CGameBoardElement* board[BOARDSIZE][BOARDSIZE];

	public:
		CGameBoard();
		CGameBoardElement* get_element(int row, int col);
		void set_element(int row, int col, CGameBoardElement* newElement);
};

#endif