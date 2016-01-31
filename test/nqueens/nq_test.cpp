#include <cstdlib>

#include "gtest/gtest.h"
#include "nqueens/n_queens.h"


TEST (nqTest, init){
	Board b(4);

	EXPECT_EQ(b.n_, 4);
	EXPECT_EQ(b.positions_.size(), 16);
}

TEST (nqTest, isvalid_empty){
	int n = 4;
	Board b(n);
	srand(time(NULL));

	int col = rand() % n;
	ASSERT_TRUE(b.is_valid(0,col));
}

TEST (nqTest, create_new_queen4_empty){
	int n = 4;
	Board b(n);
	srand(time(NULL));

	int result = b.create_new_queen(0);
	ASSERT_EQ(0, result);
}

TEST (nqTest, create_new_queen4_all){
	int n = 4;
	Board b(n);
	srand(time(NULL));

	int moves = 0;
	int result = 0;
	while(moves != (n - 1)){
		result = b.create_new_queen(result);
	}
	ASSERT_EQ(0, result);
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
