#include <iostream>
#include <cstdlib>

#include "nqueens/n_queens.h"

int main(int argc, char **argv){
	srand(time(NULL));

	int n;
	if(argc == 2)
		n = atoi(argv[1]);
	else
		n = 0;

	while(n < 4){
		std::cout<<"please input a number > 3:"<<std::endl;
		std::cin>>n;
	}

	Board b(n);
	int myMoves = 0;
	int current_col = rand() % n;
	while(b.moves_.size() != n){
		current_col = b.create_new_queen(current_col);
	}
	std::cout<<b<<std::endl;
	return 0;
}
