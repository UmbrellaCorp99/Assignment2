class logic
{
public:
	void setup();
	void already_played();
	char get_shape(int index, int index2);
	void set_shape(int index, int index2, char c);
	void compare();
	void reset_clear();
	void random_create();
private:
	char boardPattern[5][5];
	char playedBoard[5][5];
};

