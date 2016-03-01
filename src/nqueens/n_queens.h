#ifndef n_queens_h
#define n_queens_h

#include <iostream>
#include <vector>

class board {
private:
	std::vector<std::vector<bool> > positions_;
	std::vector<int> moves_;
	int size_;

public:

	board(int n);

	bool is_valid(int row, int col);

	int create_new_queen(int starting_col);

	void print(std::ostream &out) const;

	//getters
	size_t get_pos_size() const {return positions_.size();}
	size_t get_moves_size() const {return moves_.size();}
	size_t get_size() const {return size_;}
};

std::ostream &operator<<(std::ostream &out, const board &b);

#endif
