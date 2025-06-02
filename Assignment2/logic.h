#include <algorithm>
#include <string>

class logic
{
public:
	void setup();
	char get_shape(int index, int index2);
	void set_shape(int index, int index2, char c);
	bool compare(int i, int j, int k, int l);
	void reset_clear();
	void correctGuess(int index, int index2);
private:
	//The multilevel array that holds caracters representing a shape
	char boardPattern[5][5];
};

