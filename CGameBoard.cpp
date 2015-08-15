#include "CGameBoard.h"

// Constructor
CGameBoard::CGameBoard()
{

}

CGameBoardElement* CGameBoard::get_element(int row, int col)
{
	return board[row][col];
}

void CGameBoard::set_element(int row, int col, CGameBoardElement* newElement)
{
	board[row][col] = newElement;
}