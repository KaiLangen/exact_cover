#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <fstream>

#include "sudoku/eraser.h"

sudoku_grid::sudoku_grid(std::string filename){
	//assert that has the correct file extension
//	boost::filesystem::path p(filename.c_str());
//	std::string ext = p.extension();
//	assert(strcmp(ext,".sudoku") == 0);

	std::ifstream myfile(filename.c_str());
	if(myfile.is_open()){
		//fill with elements from myfile
		for(int i = 0; i < n_; ++i){
			for(int j = 0; j < n_; ++j){
				myfile >> grid_[i][j];
			}
		}

		//the number of filled cells is n x n
		filled_ = n_ * n_;
	}
	else{
		std::cerr<<"error: unable to open input file"<<std::endl;
		exit(EXIT_FAILURE);
	}
}

void sudoku_grid::remove_quad(int row, int col){
	//symmetrically remove a set of four numbers from the puzzle
	grid_[row][col] = 0;
	grid_[n_ - 1 - row][n_ - 1 - col] = 0;
	grid_[col][row] = 0;
	grid_[n_ - 1 - col][n_ - 1 - row] = 0;
	filled_ -= 4;
}

void sudoku_grid::remove_pair(int row, int col){
	//symmetrically remove a set of four numbers from the puzzle
	grid_[row][col] = 0;
	grid_[col][row] = 0;
	filled_ -= 2;
}

bool sudoku_grid::is_valid_quad(int row, int col) const{
	if((grid_[row][col] != 0) &&
		(grid_[n_ - 1 - row][n_ - 1 - col] != 0) &&
		(grid_[col][row] != 0) &&
		(grid_[n_ - 1 - col][n_ - 1 - row] != 0)){
		return true;
	}
	else
		return false;
}

bool sudoku_grid::is_valid_pair(int row, int col) const{
	if((grid_[row][col] != 0) &&
		(grid_[col][row] != 0)){
		return true;
	}
	else
		return false;
}

bool sudoku_grid::is_in_range() const{
	return (filled_ < 31);
}

void sudoku_grid::print(std::ostream &out) const{
	int elem;
	for (int i = 0; i < n_; ++i){
		for (int j = 0; j < n_; ++j){
			elem = grid_[i][j];
			if(elem == 0)
				out << "\033[1;31m"<<elem<<"\033[0m ";
			else
				out<<elem<<" ";
		}
		out<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const sudoku_grid &sg){
	sg.print(out);
	return out;
}

void construct_puzzle(sudoku_grid& sg){
	//base success case
	if(sg.is_in_range()){
		return;
	}

	//select random row/col
	int row = rand()%n_;
	int col = rand()%n_;
	for(int i = 0; i < n_; ++i){
		if(sg.is_valid_quad(row, col)){
			//quad_changed = sg.remove_quad(row, col);
			sg.remove_quad(row, col);
			construct_puzzle(sg);
			return;
		}
		++row;
		row = row % n_;
		++col;
		col = col % n_;
	}
}
