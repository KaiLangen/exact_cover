#include <iostream>

#include "nqueens/n_queens.h"

int main(){
	int n = 0;
	while(n < 4){
		std::cout<<"please input a number > 3:"<<std::endl;
		std::cin>>n;
	}

	Board b(n);
	int myMoves = 0;
	int current_col = 0;
//	while(myMoves != (n - 1)){
		current_col = b.create_new_queen(current_col);
//	}

	return 0;
}
