#include <iostream>
#include <cstdlib>

#include "nqueens/n_queens.h"

int main(int argc, char **argv){
	srand(time(NULL));

	int n;
	//can take size as a command line argument or from cin
	if(argc == 2)
		n = atoi(argv[1]);
	else
		n = 0;

	while(n < 4){
		std::cout<<"please input a number > 3:"<<std::endl;
		std::cin>>n;
	}

	board b(n);
	int myMoves = 0;
	int current_col = rand() % n;
	b.create_queens_recursive(current_col);
	/*while(b.get_moves_size() != n){
		current_col = b.create_new_queen(current_col);
	}*/
	std::cout<<b<<std::endl;
	return 0;
}
