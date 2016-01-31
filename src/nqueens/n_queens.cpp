#include <cstdlib>
#include <cmath>

#include "nqueens/n_queens.h"

Board::Board(int n){
	srand(time(NULL));

	n_ = n;
	positions_.resize(n*n);

	//set initial row and col values for each position
	for (size_t i = 0; i < n; ++i){
		for (size_t j = 0; j < n; ++j){
			positions_[i*n + j].row = i;
			positions_[i*n + j].col = j;
		}
	}
}

bool Board::is_valid(int row, int col){
	//look at all queens already on the board
	int moves_row = 0;
	int moves_col = 0;
	for(size_t i = 0; i < moves_.size(); ++i){
		moves_row = moves_[i] / n_;
		moves_col = moves_[i] % n_;
		//check for shared columns
		if(col == moves_col){
			return false;
		}
		//check for shared diagonals
		int horz_diff = abs(col - moves_col);
		int vert_diff = abs(row - moves_row);

		if(horz_diff == vert_diff){
			return false;
		}
	}
	return true;
}

int Board::create_new_queen(int starting_col){
	int newrow = moves_.size();
	int newcol = starting_col;
	int index;
	//check each possible col for valid place
	for(newcol = starting_col; newcol < n_; ++newcol){
		if(is_valid(newrow, newcol)){
			index = (newrow * n_) + newcol;
			//if move is valid, add to move history and return 0
			moves_.push_back(index);
			positions_[index].has_queen = true;
			return 0;
		}
	}
	//if reached this section, there are no valid spots in this row
	//reset previous move (and claim as invalid)
	if(moves_.size() > 0){
		newcol = (moves_.back() % n_) + 1;
		positions_[moves_.back()].has_queen = false;
		moves_.pop_back();
	}
	else
		newcol = 0;

	return newcol;
}

void Board::print(std::ostream &out) const{
	for(size_t i = 0; i < moves_.size(); ++i){
		int ro = moves_[i]/n_;
		int co = moves_[i]%n_;
		std::cout<<"queen "<<i<<":("<<ro<<","<<co<<")"<<std::endl;
	}

	for (size_t i = 0; i < n_; ++i){
		for (size_t j = 0; j < n_; ++j){
			if(positions_[(i * n_) + j].has_queen)
				out<<1;
			else
				out<<0;

			out<<" ";
		}
		out<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Board &b){
	b.print(out);
	return out;
}
