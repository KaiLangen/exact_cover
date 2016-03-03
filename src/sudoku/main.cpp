#include <iostream>
#include <cstdlib>

#include "sudoku/sudoku.h"

int main(int argc, char **argv){
	puzzle p;
	p.fill_cell(0);
	std::cout<<p<<std::endl;
	return 0;
}
