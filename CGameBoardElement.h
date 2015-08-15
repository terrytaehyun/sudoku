#ifndef CGAMEBOARDELEMENT_H
#define CGAMEBOARDELEMENT_H

enum States 
{
	Empty,
	Given,
	Found,
	Trial
};

class CGameBoardElement 
{
	private:
		/* 'number' variable is used to store the value used to solve the Sudoku board. 
		 *  Value stored in the 'number' variable must be within 1 to 9, or the 'No value' (0 is used) to indicate empty field.
		 */
		int number;

		/* 'state' variable is used to describe the current state of the element. 
		 *  It may have one of four possible values: Empty, Given, Found, or Trial.
		 * 'Empty' is the inital value to indicate that the value in the element is garbage,
		 * 'Given' is used to indicate the number of this element was given from the start of the game,
		 * 'Found' is used to indicate the number of this element was found from the solver, and is the correct one,
		 * 'Trial' is used to indicate the number of this element is under evaluation by the sovler, and may change in the future.
		 *  Only 'Given' and 'Found' state is final values. Value with 'Trial' flag can be changed.
		 */
		States state;

		// Contains possible numbers that can end up in the board.
		std::set<int> possibilities; 
		
		// Stores value that is under evaluation.
		int eval_storage; 


	public:
		// Constructor
		CGameBoardElement();
		CGameBoardElement(int _num);

		// Setters
		int set_number(int newNumber);
		int set_state(States newState);
		int set_evalStorage (int pulledOutNumber);

		// Getters
		int get_number();
		States get_state();

};

#endif