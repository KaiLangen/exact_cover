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

struct slot {
	group* col_;
	group* row_;
	group* square_;
	int val_;

	slot(int row, int col, puzzle* p);
};


struct puzzle {
	boost::array<group, n_> rows_;
	boost::array<group, n_> cols_;
	boost::array<group, n_> squares_;

	std::vector<slot> slots_;

	puzzle();

	bool fill_slot(size_t index);

	void print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const puzzle &p);

#endif
