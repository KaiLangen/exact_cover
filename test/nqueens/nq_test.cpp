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

TEST (nqTest, isvalid_second_row){
	int n = 4;
	Board b(n);
	srand(time(NULL));

	b.moves_.push_back(0);
	int col = rand() % n;
	ASSERT_TRUE(b.is_valid(1,col));
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
