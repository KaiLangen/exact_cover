/**
* Generates a solvable sudoku puzzle
*/
#ifndef eraser_h
#define eraser_h

#include <string>

#include "sudoku/generator.h"

//declared in generator.h
extern const int n_; //puzzle is of size n x n
extern const int sqrt_; //puzzle is of size n x n

/**
* sudoku_grid
* transposes a file created by generator into a grid
*/
class sudoku_grid {
private:
	//create empty 2d array
	 int grid_[n_][n_];
	 int filled_;

public:
	/**
	* Creates a completed sudoku grid from the file provided
	*/
	sudoku_grid(std::string filename);

	/**
	* Removes a single cell at (row, col)
	*/
	void remove_cells(int row, int col);

	/**
	* Removes a single cell at (row, col) then removes 3 others
	* by mirroring the row and/or col about the centre
	*/
	void remove_quad(int row, int col);

	/**
	* Removes a single cell at (row, col) then removes 1 other
	* by mirroring bothe the row and column about the centre
	*/
	void remove_pair(int row, int col);

	/**
	* Checks if the quad is valid
	* (i.e. have any cells been removed yet? NO = VALID)
	*/
	bool is_valid_quad(int row, int col) const;

	/**
	* Same as is_valid_quad but for pairs
	*/
	bool is_valid_pair(int row, int col) const;

	/**
	* Checks to see whether the puzzle is in the solvable range
	* (where the number of filled cells is less than 31)
	*/
	bool is_in_range() const;

	/**
	* Gets cell at (row, col)
	*/
	bool get_elem(int row, int col) const { return grid_[row][col]; }

	/**
	* Prints the current puzzle to stdout
	*/
	void print(std::ostream &out) const;
};

//non-member functions

/**
* master function that constructs a solvable puzzle
*/
void construct_puzzle(sudoku_grid &sg);

/**
* Allows the sudoku grid class to be printable to an output stream
*/
std::ostream &operator<<(std::ostream &out, const sudoku_grid &sg);

#endif
