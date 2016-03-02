#include <iostream>
#include <cstdlib>

#include "sudoku/sudoku.h"

int main(int argc, char **argv){
	puzzle p;
	p.fill_slot(0);
	std::cout<<p<<std::endl;
	return 0;
}
