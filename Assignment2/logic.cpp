//Alexander Young
//Assignment 2

#include "logic.h"

void logic::setup() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			boardPattern[i][j] = 'n';
		}
	}
}

void logic::already_played() {

}
char logic::get_shape(int index, int index2) {
	return boardPattern[index][index2];
}
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

}
void logic::random_create() {

}
void logic::correctGuess(int index, int index2) {
	boardPattern[index][index2] = 'X';
}

