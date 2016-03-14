#ifndef solver_h
#define solver_h

#include <string>
#include <set>

#include "sudoku/eraser.h"
#include "sudoku/generator.h"

//declared in generator.h
extern const int n_; //puzzle is of size n x n
extern const int sqrt_; //puzzle is of size n x n

/**
 * solver_cell
 * used by the solver function to represent sudoku puzzle cells
 */
struct solver_cell{
	int val_;
	std::set<int> possible_vals_;

	solver_cell(int val):val_(val) {}
};

bool solve(const sudoku_grid &sg);

#endif
