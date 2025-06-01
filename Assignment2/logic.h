class logic
{
public:
	void setup();
	void already_played();
	char get_shape(int index, int index2);
	void set_shape(int index, int index2, char c);
	bool compare(int i, int j, int k, int l);
	void reset_clear();
	void random_create();
	void correctGuess(int index, int index2);
private:
	char boardPattern[5][5];
	char playedBoard[5][5];
};

