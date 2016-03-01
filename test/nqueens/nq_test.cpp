#include <cstdlib>

#include "gtest/gtest.h"
#include "nqueens/n_queens.h"


TEST (nqTest, init){
	board b(4);

	EXPECT_EQ(b.get_size(), 4);
	EXPECT_EQ(b.get_pos_size(), 16);
}

TEST (nqTest, isvalid_empty){
	srand(time(NULL));
	int n = rand()%10 + 4;
	board b(n);
	srand(time(NULL));

	int col = rand() % n;
	ASSERT_TRUE(b.is_valid(0,col));
}

TEST (nqTest, isvalid_test){
	srand(time(NULL));
	int n = rand()%10 + 4;
	board b(n);
	srand(time(NULL));

	int col = rand() % n;
	b.create_new_queen(3);
	ASSERT_FALSE(b.is_valid(1,3));
}

TEST (nqTest, create_new_queen_empty){
	srand(time(NULL));
	int n = rand()%10 + 4;
	board b(n);
	srand(time(NULL));

	int result = b.create_new_queen(0);
	ASSERT_EQ(0, result);
}

TEST (nqTest, create_new_queen_all){
	srand(time(NULL));
	int n = rand()%10 + 4;
	std::cout<<n<<std::endl;
	board b(n);
	srand(time(NULL));

	int result = 0;
	while(b.get_moves_size() != (n - 1)){
		result = b.create_new_queen(result);
	}
	ASSERT_EQ(0, result);
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
