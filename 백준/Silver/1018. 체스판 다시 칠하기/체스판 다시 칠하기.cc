#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

string	b_line = "BWBWBWBW";
string	w_line = "WBWBWBWB";

int	count_diff_in_line(const string& line, const string& standard_line, int idx)
{
	int	cnt = 0;
	for (size_t i = 0; i < standard_line.size(); ++i)
	{
		if (standard_line[i] != line[i + idx])
		{
			++cnt;
		}
	}
	return (cnt);
}

int	count_paint(const vector<string>& board, int idx, size_t jdx)
{
	int	b_count = 0;
	int	w_count = 0;
	for (size_t i = idx; i < idx + 8; ++i)
	{
		if (i % 2 == 0) {
			b_count += count_diff_in_line(board[i], b_line, jdx);
			w_count += count_diff_in_line(board[i], w_line, jdx);
		} else {
			b_count += count_diff_in_line(board[i], w_line, jdx);
			w_count += count_diff_in_line(board[i], b_line, jdx);
		}
	}
	return (min(b_count, w_count));
}

int	main()
{
	int	n, m;
	cin >> n >> m;
	vector<string>	board;
	set<int>	st;
	for (int i = 0; i < n; ++i)
	{
		string	line;
		cin >> line;
		board.push_back(line);
	}
	for (size_t i = 0; i + 7 < board.size(); ++i) {
		for (size_t j = 0; j + 7 < board[i].size(); ++j) {
			st.insert(count_paint(board, i, j));
		}
	}
	cout << *st.begin() << '\n';
}
