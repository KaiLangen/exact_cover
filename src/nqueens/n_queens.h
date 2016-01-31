#ifndef n_queens_h
#define n_queens_h

#include <iostream>
#include <vector>

class Board {
private:
	struct Position{
		int col;
		int row;
		bool has_queen;

		Position(): col(0), row(0), has_queen(false) {}
	};

public:
	std::vector<Position> positions_;
	std::vector<int> moves_;
	int n_;

	Board(int n);

	bool is_valid(int row, int col);

	int create_new_queen(int starting_col);

	void print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const Board &b);

#endif
