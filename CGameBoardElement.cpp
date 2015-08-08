#include <stdio.h>
#include <iostream>
#include "CGameBoardElement.h"

using namespace std;

// Constructors
CGameBoardElement::CGameBoardElement() 
{
	number = 0;
	state = Empty;
}


// Setters
int CGameBoardElement::set_number(int newNumber)
{
	// Sanity check: newNumber must be within 1-9
	if (newNumber < 1 || newNumber > 9)
	{
		perror("CGameBoardElement - Warning: newNumber is out of bound");
		return -1;
	}

	number = newNumber;
	return 0;
}

int CGameBoardElement::set_state(States newState)
{
	// Sanity check: newState must be one of Empty, Given, Found, or Trial
	if ( !((newState == Empty) || (newState == Given) || (newState == Found) || (newState == Trial)) )
	{
		perror("CGameBoardElement - Warning: Unknown newState");
		return -1;
	}

	state = newState;
	return 0;
}

// Getters
int CGameBoardElement::get_number()
{
	return number;
}

States CGameBoardElement::get_state()
{
	return state;
}