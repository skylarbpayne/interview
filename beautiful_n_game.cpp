/**
 * Author: Skylar Payne
 * Date: January 8, 2015
 * Initially there is a number n written on the board. Two players start playing a game turn by turn.
 *  Each player replaces n with n - 2^k where k is a natural number and 2^k < n.
 *  The new number also has to have the same number of set bits in binary representation.
 *  If each player plays optimally, who wins given n?
 **/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
#include <assert.h>

bool p1_wins(int n, std::unordered_map<int, bool>& moves) {
	if(moves.find(n) != moves.end()) {
		return moves[n];
	}
	//find all valid moves.
	//for each move, moves[n] = moves[n] || !p1_wins(move)
	int msb_set;
	for(msb_set = sizeof(int) * 8 - 1; ((n >> msb_set) & 1) == 0; --msb_set); // find msb set bit
	std::vector<int> valid_moves;
	for(int i = 0; i <= msb_set; ++i) {
		if(((n >> i) & 1) == 0) {
			valid_moves.push_back(i);
		}
	}
	bool res = false;
	for(int i = 0; i < valid_moves.size(); ++i) {
		res = res || !p1_wins(n - (1 << valid_moves[i]), moves);
	}
	moves[n] = res;
	return res;
}

bool is_p1_winner(int n) {
	if(n == 0) {
		return false;
	}
	std::unordered_map<int, bool> moves;
	return p1_wins(n, moves);
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Please provide n" << std::endl;
		return -1;
	}
	//assert(is_p1_winner(3) == false);
	//assert(is_p1_winner(5) == true);

	std::cout << (is_p1_winner(atoi(argv[1])) ? "Player 1" : "Player 2") << " is the winner!" << std::endl;
	return 0;
}
