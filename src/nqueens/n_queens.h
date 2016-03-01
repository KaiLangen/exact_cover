#ifndef n_queens_h
#define n_queens_h

#include <iostream>
#include <vector>

class board {
typedef std::pair<int,int> pos;
private:
	std::vector<std::vector<bool> > positions_;
	std::vector<pos> moves_;
	int size_;

public:

	board(int n);

	bool is_valid(int row, int col);

	bool create_queens_recursive(int current_col);

	bool create_queens_recursive();

	int create_new_queen(int starting_col);

	void print(std::ostream &out) const;

	//getters
	size_t get_pos_size() const {return positions_.size();}
	size_t get_moves_size() const {return moves_.size();}
	size_t get_size() const {return size_;}
};

std::ostream &operator<<(std::ostream &out, const board &b);

#endif
