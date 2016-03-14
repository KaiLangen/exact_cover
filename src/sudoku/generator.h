#ifndef generator_h
#define generator_h

#include <boost/array.hpp>
#include <iostream>
#include <vector>
#include <math.h>

//forward declaration of solution
struct solution;

const int n_ = 9;
const int sqrt_ = sqrt(n_);

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
	unsigned int val_;

	cell(int row, int col, solution* s);
};


struct solution {
	boost::array<group, n_> rows_;
	boost::array<group, n_> cols_;
	boost::array<group, n_> squares_;
	boost::array<unsigned int, n_> vals_;

	std::vector<cell> cells_;

	solution();

	bool fill_cell(size_t index);

	void randomize_first_row();

	void print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const solution &s);

#endif
