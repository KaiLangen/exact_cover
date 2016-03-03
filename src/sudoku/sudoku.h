#ifndef sudoku_h
#define sudoku_h

#include <boost/array.hpp>
#include <iostream>
#include <vector>
#include <math.h>

//forward declaration of puzzle
struct puzzle;

static const int n_ = 9;
static const int sqrt_ = sqrt(n_);

struct group {
	boost::array<bool, n_> available_;

	group(){
		for(int i = 0; i < n_; ++i){
			available_[i] = true;
		}
	}
};

struct cell {
	group* col_;
	group* row_;
	group* square_;
	unsigned int* val_;

	cell(int row, int col, puzzle* p);
};


struct puzzle {
	boost::array<group, n_> rows_;
	boost::array<group, n_> cols_;
	boost::array<group, n_> squares_;
	unsigned int grid_[n_][n_];

	std::vector<cell> cells_;

	puzzle();

	bool fill_cell(size_t index);

	void randomize_first_row();

	void print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const puzzle &p);

#endif
