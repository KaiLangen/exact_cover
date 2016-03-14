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
	sudoku_grid(std::string filename);

	void remove_cells(int row, int col);

	void remove_quad(int row, int col);

	void remove_pair(int row, int col);

	bool is_valid_quad(int row, int col) const;

	bool is_valid_pair(int row, int col) const;

	bool is_in_range() const;

	bool get_elem(int row, int col) const { return grid_[row][col]; }

	void print(std::ostream &out) const;
};

/**
 * non-member functions
 */
void construct_puzzle(sudoku_grid &sg);

std::ostream &operator<<(std::ostream &out, const sudoku_grid &sg);

#endif
