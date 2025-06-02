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

//This function compares the value at two specified indexes. If the same index is chosed or the elements do not match, it will return false
//Takes four integers representing two different indexes
//Returns a boolean value
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

//This functions calls the setup() function when called
//Takes no parameters
//No return
void logic::reset_clear() {
	setup();
}

//This function changes the value at a specified index to the letter 'X' indicating that it is part of a matched pair
//Takes two integers representing an index
//No return
void logic::correctGuess(int index, int index2) {
	boardPattern[index][index2] = 'X';
}

