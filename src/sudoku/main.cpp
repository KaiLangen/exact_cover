#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>

#include "sudoku/eraser.h"
#include "sudoku/generator.h"
#include "sudoku/solver.h"

int main(int argc, char **argv){
	//generate a sudoku puzzle solution
	srand(time(NULL));
	solution p;
	std::cout<<p<<std::endl;
	int tag = rand()%1000;

	//output it to a .sudoku file
	std::stringstream filename;
	filename<<"puzzle_"<<tag<<".sudoku";

	std::ofstream myfile(filename.str().c_str());
	if(myfile.is_open()){
		myfile<<p;
	}
	else{
		std::cerr<<"error: unable to open output file"<<std::endl;
		exit(EXIT_FAILURE);
	}

	//transpose it to a grid and generate a puzzle
	//by removing cells so it can be solved by a human
	sudoku_grid sg(filename.str());
	construct_puzzle(sg);
	std::cout<<sg<<std::endl;
	solve(sg);

	return 0;
}
