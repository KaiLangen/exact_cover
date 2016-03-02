#include "sudoku/sudoku.h"

slot::slot(int row, int col, puzzle* p){
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
	for(int i = 0; i < n_; ++i){
		for(int j = 0; j < n_; ++j){
			slots_.push_back(slot(i,j, this));
		}
	}
}

bool puzzle::fill_slot(size_t index){
	// base success case
	if(index == slots_.size()){
		return true;
	}
	slot& s = slots_[index];

	//recursive case
	for(int i = 0; i < n_; ++i){
		if(s.row_->available_[i] &&
		   s.col_->available_[i] &&
		   s.square_->available_[i]){

			s.row_->available_[i] = false;
			s.col_->available_[i] = false;
			s.square_->available_[i] = false;
			s.val_ = i+1;
			//fill the next slot
			if(fill_slot(index + 1)){
				return true;
			}
			else{
				//reset and continue iterating
				s.val_ = 0;
				s.row_->available_[i] = true;
				s.col_->available_[i] = true;
				s.square_->available_[i] = true;
			}
		}
	}
	//default failure case
	return false;
}

void puzzle::print(std::ostream &out) const{
	for (size_t i = 0; i < n_; ++i){
		for (size_t j = 0; j < n_; ++j){
			slot s = slots_[(i*n_) + j];
			out<<s.val_<<" ";
		}
		out<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const puzzle& p){
	p.print(out);
	return out;
}
