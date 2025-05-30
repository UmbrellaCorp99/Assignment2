class logic
{
public:
	bool already_played();
	void get_shape(int index);

private:
	char pattern[5][5];
	char playedBoard[5][5];
};

