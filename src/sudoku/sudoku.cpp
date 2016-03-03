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

	val_ = 0;
}

puzzle::puzzle(){
	srand(time(NULL));
	for(int i = 0; i < n_; ++i){
		for(int j = 0; j < n_; ++j){
			cells_.push_back(cell(i,j, this));
		}
	}

	//fill vals array with values 1 - n
	for(size_t i = 0; i < n_; ++i)
		vals_[i] = i;

	//fill first row
	randomize_first_row();
	std::cout<<*this<<std::endl;

	//randomize vals_ order a second time
	//remaining cells will resolve in this order
	std::random_shuffle(vals_.begin(), vals_.end());

	//recursively fill remaining cells
	//starting on the second row
	fill_cell(n_);
}

void puzzle::randomize_first_row(){
	srand(time(NULL));

	//randomize their order
	std::random_shuffle(vals_.begin(), vals_.end());

	//insert into first row
	for(size_t i = 0; i < n_; ++i){
		cells_[i].val_ = vals_[i] + 1;
		cells_[i].row_->available_[vals_[i]] = false;
		cells_[i].col_->available_[vals_[i]] = false;
		cells_[i].square_->available_[vals_[i]] = false;
	}
}

bool puzzle::fill_cell(size_t index){
	// base success case
	if(index == cells_.size()){
		return true;
	}

	cell& c = cells_[index];
	int val = 0;

	//recursive case
	for(int i = 0; i < n_; ++i){
		val = vals_[i];
		if(c.row_->available_[val] &&
		   c.col_->available_[val] &&
		   c.square_->available_[val]){

			c.row_->available_[val] = false;
			c.col_->available_[val] = false;
			c.square_->available_[val] = false;
			c.val_ = val + 1;
			//fill the next cell
			if(fill_cell(index + 1)){
				return true;
			}
			else{
				//reset and continue iterating
				c.val_ = 0;
				c.row_->available_[val] = true;
				c.col_->available_[val] = true;
				c.square_->available_[val] = true;
			}
		}
	}
	//default failure case
	return false;
}

void puzzle::print(std::ostream &out) const{
	for (size_t i = 0; i < n_; ++i){
		for (size_t j = 0; j < n_; ++j){
			cell c = cells_[(i*n_) + j];
			out<<c.val_<<" ";
		}
		out<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const puzzle& p){
	p.print(out);
	return out;
}
