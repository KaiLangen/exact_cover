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
	std::vector<pos>::iterator it = moves_.begin();
	for(; it != moves_.end(); ++it){
		//check for shared columns
		if(col == it->second){
			return false;
		}
		//check for shared diagonals
		int horz_diff = abs(col - it->second);
		int vert_diff = abs(row - it->first);

		if(horz_diff == vert_diff){
			return false;
		}
	}
	return true;
}

void board::print(std::ostream &out) const{
	for(size_t i = 0; i < moves_.size(); ++i){
		int ro = moves_[i].first;
		int co = moves_[i].second;
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

//starting point for recursive functions
bool board::create_queens_recursive(int current_col){
	do{
		//if column is outside of range, exit error
		if(current_col <= size_){
			std::cout<<"Error: no valid solutions"<<std::endl;
			exit(EXIT_FAILURE);
		}

		//get rid of previous state
		moves_.clear();
		if(current_col > 0)
			positions_[0][current_col - 1] = false;

		//set first queen at column = current_col
		moves_.push_back(pos(0, current_col));
		positions_[0][current_col] = true;
		++current_col;
	} while(!create_queens_recursive());
}

bool board::create_queens_recursive(){
	int newrow = moves_.size();
	//completion base case! NQueens is solved
	if(newrow == size_){
		return true;
	}
	for(int newcol = 0; newcol < size_; ++newcol){
		if(is_valid(newrow, newcol)){
			//if move is valid, add to move history and return 0
			moves_.push_back(pos(newrow, newcol));
			positions_[newrow][newcol] = true;
			//recursively call create_new_queen
			if(create_queens_recursive())
				return true;

			//otherwise, remove previous move from moves_ and positions_
			//continue to iterate through columns
			positions_[newrow][newcol] = false;
			moves_.pop_back();
		}
	}
	//if reached this section, there are no valid spots in this row
	return false;
}

//Non recursive solution (dynamic??)
int board::create_new_queen(int starting_col){
	int newrow = moves_.size();
	int newcol = starting_col;
	//check each possible col for valid place
	for(; newcol < size_; ++newcol){
		if(is_valid(newrow, newcol)){
			//if move is valid, add to move history and return 0
			moves_.push_back(pos(newrow, newcol));
			positions_[newrow][newcol] = true;
			return 0;
		}
	}
	//if reached this section, there are no valid spots in this row
	//backtrack to previous row (starting at prev column + 1)
	//set previous move as false and remove from move list
	if(moves_.size() > 0){
		std::cout<< "Row: "<<newrow<<"Col: "<<newcol<<std::endl;
		pos last = moves_.back();
		positions_[last.first][last.second] = false;
		newcol = last.second + 1;
		moves_.pop_back();
	}
	//if there are no previous moves left, placement should not fail!
	else{
		std::cout<<"Error: no previous moves left"<<std::endl;
		exit(EXIT_FAILURE);
	}
	return newcol;
}

std::ostream &operator<<(std::ostream &out, const board &b){
	b.print(out);
	return out;
}
