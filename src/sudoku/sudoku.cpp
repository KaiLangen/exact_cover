#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

#include "sudoku/sudoku.h"

cell::cell(int row, int col, puzzle* p){
	//row and column assignment is straight-forward
	row_ = &(p->rows_[row]);
	col_ = &(p->cols_[col]);

	//square assignment is a little more complicated
	//for n = 9, squares would be:
	// 0 1 2
	// 3 4 5
	// 6 7 8
	//
	int sq_index = (col/sqrt_) + (row/sqrt_) * sqrt_;
	square_ = &(p->squares_[sq_index]);

	//val points to the uint value in grid_ at [row][col]
	val_ = &(p->grid_[row][col]);
	*(val_) = 0;
}

puzzle::puzzle(){
	srand(time(NULL));
	//initialize grid to zeros
	for(int i = 0; i < n_; ++i){
		for(int j = 0; j < n_; ++j){
			cells_.push_back(cell(i,j, this));
		}
	}
	//fill first row
//	randomize_first_row();
//	std::cout<<*this<<std::endl;

	//randomize cell order
	std::random_shuffle(cells_.begin(), cells_.end());

	//recursively fill remaining cells
	//starting on the second row
	fill_cell(n_);
}

void puzzle::randomize_first_row(){
	srand(time(NULL));
	//create a row of vals from 1 to n
	std::vector<int> vals;
	for(size_t i = 0; i < n_; ++i)
		vals.push_back(i);

	//randomize their order
	std::random_shuffle(vals.begin(), vals.end());

	//insert into first row
	for(size_t i = 0; i < n_; ++i){
		*(cells_[i].val_) = vals[i] + 1;
		cells_[i].row_->available_[vals[i]] = false;
		cells_[i].col_->available_[vals[i]] = false;
		cells_[i].square_->available_[vals[i]] = false;
	}
}

bool puzzle::fill_cell(size_t index){
	// base success case
	if(index == cells_.size()){
		return true;
	}
	cell& c = cells_[index];

	//recursive case
	for(int i = 0; i < n_; ++i){
		if(c.row_->available_[i] &&
		   c.col_->available_[i] &&
		   c.square_->available_[i]){

			c.row_->available_[i] = false;
			c.col_->available_[i] = false;
			c.square_->available_[i] = false;
			*(c.val_) = i+1;
			//fill the next cell
			if(fill_cell(index + 1)){
				return true;
			}
			else{
				//reset and continue iterating
				*(c.val_) = 0;
				c.row_->available_[i] = true;
				c.col_->available_[i] = true;
				c.square_->available_[i] = true;
			}
		}
	}
	//default failure case
	*(c.val_) = 10;
	std::cout<<*this<<std::endl;
	exit(EXIT_FAILURE);
	return false;
}

void puzzle::print(std::ostream &out) const{
	for (size_t i = 0; i < n_; ++i){
		for (size_t j = 0; j < n_; ++j){
			out<<grid_[i][j]<<" ";

		}
		out<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const puzzle& p){
	p.print(out);
	return out;
}
