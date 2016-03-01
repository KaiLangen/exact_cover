#include <cstdlib>
#include <cmath>

#include "nqueens/n_queens.h"

board::board(int n){
	srand(time(NULL));

	size_ = n;
	positions_.resize(n*n);

	//set each position as false (does not contain a queen)
	for (size_t i = 0; i < n; ++i){
		positions_[i].resize(n);
		for(size_t j = 0; j < n; ++j){
			positions_[i][j] = false;
		}
	}
}

bool board::is_valid(int row, int col){
	//look at all queens already on the board
	int moves_row = 0;
	int moves_col = 0;
	for(size_t i = 0; i < moves_.size(); ++i){
		moves_row = moves_[i] / size_;
		moves_col = moves_[i] % size_;
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

int board::create_new_queen(int starting_col){
	int newrow = moves_.size();
	int newcol = starting_col;
	int index;
	//check each possible col for valid place
	for(; newcol < size_; ++newcol){
		if(is_valid(newrow, newcol)){
			index = (newrow * size_) + newcol;
			//if move is valid, add to move history and return 0
			moves_.push_back(index);
			positions_[newrow][newcol] = true;
			std::cout<<*this<<std::endl;
			return 0;
		}
	}
	//if reached this section, there are no valid spots in this row
	//backtrack to previous row (starting at prev column + 1)
	//set previous move as false and remove from move list
	if(moves_.size() > 0){
		std::cout<< "Row: "<<newrow<<"Col: "<<newcol<<std::endl;
		index = moves_.back();
		positions_[(index/size_)][(index%size_)] = false;
		newcol = (index % size_) + 1;
		moves_.pop_back();

		std::cout<<*this<<std::endl;
	}
	//if there are no previous moves left, placement should not fail!
	else{
		std::cout<<"new column is: "<<newcol<<std::endl;
		std::cout<<"Error: no previous moves left"<<std::endl;
		exit(EXIT_FAILURE);
	}
	return newcol;
}

void board::print(std::ostream &out) const{
	for(size_t i = 0; i < moves_.size(); ++i){
		int ro = moves_[i]/size_;
		int co = moves_[i]%size_;
		std::cout<<"queen "<<i<<":("<<ro<<","<<co<<")"<<std::endl;
	}

	for (size_t i = 0; i < size_; ++i){
		for (size_t j = 0; j < size_; ++j){
			if(positions_[i][j])
				out<<1;
			else
				out<<0;

			out<<" ";
		}
		out<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const board &b){
	b.print(out);
	return out;
}
