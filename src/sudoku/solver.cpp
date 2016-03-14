#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <fstream>
//#include <boost/filesystem.hpp>

#include "sudoku/solver.h"

typedef std::vector<std::vector<solver_cell> > solver_grid;

bool solve(const sudoku_grid& sg){
	return false;
}

/*
bool solve(const sudoku_grid& sg){
	//where to start?
	//create a copy of the sudoku grid
	int value;
	int sq_index;
	std::set<int> rows[n_];
	std::set<int> cols[n_];
	std::set<int> squares[n_];
	solver_grid myGrid;
	myGrid.resize(n_);
	for(int i = 0; i < n_; ++i){
		for(int j = 0; j < n_; ++j){
			solver_cell cell(sg.get_elem(i,j));
			myGrid[i].push_back(cell);
			//empty cell, fill list of possible values
			if(cell.val_ == 0){
				for(int k = 0; k < n_; ++k){
					cell.possible_vals_.insert(k);
				}
			}
			else{
				rows[i].insert(value);
				cols[j].insert(value);
				sq_index = (j/sqrt_) + ((i/sqrt_) * sqrt_);
				squares[sq_index].insert(value);
			}
		}
	}

}
	for(int i = 0; i < n_; ++i){
		for(int j = 0; j < n_; ++j){
			sq_index = (j/sqrt_) + ((i/sqrt_) * sqrt_);
			solver_cell sc = myGrid[i][j];
			if(cell.val_ == 0){
				for(int k = 0; k < rows.size(); ++k)
					cell.possible_vals_.erase(row[i]);

				for(int k = 0; k < cols.size(); ++k)
					cell.possible_vals_.erase(col[j]);

				for(int k = 0; k < squares.size(); ++k)
					cell.possible_vals_.erase(square[sq_index]);

			}
		}
	}

	//transpose cells onto a priority queue
	for(int i = 0; i < n_; ++i){
		for(int j = 0; j < n_; ++j){
			myCells.push(&myGrid[i][j]);
		}
	}

	solve(myCells);
	for(int i = 0; i < n_; ++i){
		for(int j = 0; j < n_; ++j){
			std::cout<<myGrid[i][j];
		}
	}
}

//recursive part of the solve algorithm
//with priority queue ordered by size of possible_vals
bool solve(priority_queue& myCells){
	if(myCells.empty())
		return true;

	solver_cell* cell = myCells.top();
	if(cell->possible_vals_.size() == 1){
		
	}
	else
		return false;
}
*/
