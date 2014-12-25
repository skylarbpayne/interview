/**
 * Author: Skylar Payne
 * Date: December 25, 2014
 * Pots of gold are arranged in a line, each containing some gold coins. 2 players alternate
 *  removing a pot from one of the ends. The player with the greatest number of coins at the
 *  end wins.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

bool p1_win(std::vector<int> const& pots) {
	//set of sub solutions. res[i][j] represents a game played
	// from pot i to pot j. sum(p1) - sum(p2) > 0 will tell us if p1 can win.
	std::vector<std::vector<int> > res(pots.size(), std::vector<int>(pots.size()));
	for(int i = 0; i < pots.size(); ++i) {
		//for a game with a single pot, player 1 gets that amount
		res[i][i] = pots[i];
	}
	for(int i = 0; i < pots.size(); ++i) {
		for(int j = i + 1, k = 0; j < pots.size() && k < pots.size(); ++j, ++k) {
			res[k][j] = std::max(pots[k] - res[k + 1][j], pots[j] - res[k][j - 1]);
		}
	}
	
	return res[pots.size() - 1][pots.size() - 1] > 0;
}

int main() {
	srand(time(NULL));
	unsigned int size = rand() % 200 + 50;
	std::vector<int> pots(size);
	for(int i = 0; i < size; ++i) {
		pots[i] = rand() % 100;
	}
	std::cout << p1_win(pots) << std::endl;
	return 0;
}
