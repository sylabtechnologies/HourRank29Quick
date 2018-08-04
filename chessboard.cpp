// seems OK but testk FOR TINY BOARDS!

inline string alpha_result(bool result) { return result ? "Yes" : "No"; }

bool test_adjacents(const vector<vector<int>> &board, const size_t testsize, const size_t i, const size_t j, const int color)
{
	if (j > 0 && board[i][j - 1] == color) return false;
	if (j + 1 < testsize && board[i][j + 1] == color) return false;
	if (i > 0 && board[i - 1][j] == color) return false;
	if (i + 1 < board.size() && board[i + 1][j] == color) return false;

	return true;
}

string solve(vector<vector<int>> board)
{
	bool result = true;

	// test sizes
	size_t testsize = board[0].size();

	if (testsize == 0 || board.size() == 0) return true;

	for (size_t i = 0; i < board.size(); i++)
	{
		if (board[i].size() != testsize)
		{
			result = false;
			return alpha_result(result);
		}
	}

	// test adjacents
	for (size_t i = 0; i < board.size(); i++)
	{
		for (size_t j = 0; j < board.size(); j++)
		{
			int mycolor = board[i][j];

			if (!test_adjacents(board, testsize, i, j, mycolor))
			{
				result = false;
				return alpha_result(result);
			}

		}
	}

	return alpha_result(result);
}
