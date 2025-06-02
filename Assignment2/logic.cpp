//Alexander Young
//Assignment 2

#include "logic.h"

//This function generates a string of characters representing shapes, shuffles it, and then adds them to the multilevel array "board", with the last element always being the letter 'z' for the reset
//Takes no parameters
//No return
void logic::setup() {
	std::string str = "aabbccddeeffgghhiijjkkll";
	random_shuffle(str.begin(), str.end());
	int count = 0;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++) {
			boardPattern[i][j] = str[count];
			count++;
		}
	}
	boardPattern[4][4] = 'z';
}

//This function returns the character at a given index
//Takes two integers used for the index as parameters
//Returns a char
char logic::get_shape(int index, int index2) {
	return boardPattern[index][index2];
}

//This function sets the specified index to the specified char. Used when changing the original value to the 'n' char when a pair is matched
//Takes two integers representing the index and a char as the parameters
//No return
void logic::set_shape(int index, int index2, char c) {
	boardPattern[index][index2] = c;
}
bool logic::compare(int i, int j, int k, int l) {
	bool same = false;
	if (i == k && j == l) {
		same = false;
	}
	else if (get_shape(i, j) == get_shape(k, l)) {
		same = true;
	}
	else {
		same = false;
	}
	return same;
}
void logic::reset_clear() {
	setup();
}
void logic::correctGuess(int index, int index2) {
	boardPattern[index][index2] = 'X';
}

