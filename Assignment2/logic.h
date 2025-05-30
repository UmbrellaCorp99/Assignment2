class logic
{
public:
	bool already_played();
	void get_shape();
	void set_shape();
	void compare();
	void reset_clear();
	void random_create();
private:
	char pattern[5][5];
	char playedBoard[5][5];
};

