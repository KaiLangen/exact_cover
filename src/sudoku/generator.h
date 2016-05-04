/**
* sudoku/generator.h
* Generates a completed sudoku "solution"
* indexed as follows:
*
* 1  2  3  |  4  5  6  |  7  8  9
* 10 11 12 |  13 14 15 |  16 17 18
* 19 29 21 |  22 23 24 |  25 26 27
* ________________________________
*          |           |
* ...
* and so on
*/
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

	/**
	*  cell constructor
	*/
	cell(int row, int col, solution* s);
};


struct solution {
	boost::array<group, n_> rows_;
	boost::array<group, n_> cols_;
	boost::array<group, n_> squares_;
	boost::array<unsigned int, n_> vals_;

	std::vector<cell> cells_;

	/**
	* solution constructor
	*/
	solution();

	/**
	* fills a cell at index i
	*/
	bool fill_cell(size_t index);

	/**
	* fills the first row randomly using boost::random_shuffle
	*/
	void randomize_first_row();

	/**
	* prints a solution to ostream
	*/
	void print(std::ostream &out) const;
};
//NON-MEMBER FUNCTIONS

/**
* Allows a solution to be output to an out stream
*/
std::ostream &operator<<(std::ostream &out, const solution &s);

/**
* calculates which "square" a given index belongs to
*/
inline int square_index(int row, int col){return (col/sqrt_) + (row/sqrt_) * sqrt_;}

#endif
