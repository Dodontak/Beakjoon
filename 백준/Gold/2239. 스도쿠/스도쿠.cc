#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool>	x_line(10);
vector<bool>	y_line(10);
vector<bool>	block(10);

void	init_bools(vector<bool> &block, vector<bool> &x_line, vector<bool> &y_line) {
	for (int i = 0; i < 10; ++i) {
		block[i] = false;
		x_line[i] = false;
		y_line[i] = false;
	}
}

int	is_right_board(int x, int y, const vector<string> &board) {
	int	x_block = x / 3;
	int	y_block = y / 3;
	init_bools(block, x_line, y_line);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int	num = board[y_block * 3 + i][x_block * 3 + j] - '0';
			if (num == 0) continue;
			if (block[num] == true) return false;
			block[num] = true;
		}
	}
	for (int i = 0; i < 9; ++i) {
		int	num = board[y][i] - '0';
		if (num == 0) continue;
		if (x_line[num] == true) return false;
		x_line[num] = true;
	}
	for (int i = 0; i < 9; ++i) {
		int	num = board[i][x] - '0';
		if (num == 0) continue;
		if (y_line[num] == true) return false;
		y_line[num] = true;
	}
	return true;
}

void	back_tracking(int x, int y, vector<string> &board, vector<string> &ans) {
	static bool	end = false;
	if (end == true) return;
	if (y == 9) {
		ans = board;
		end = true;
		return;
	}
	int	next_x = (x + 1 == 9 ? 0 : x + 1);
	int	next_y = (x + 1 == 9 ? y + 1 : y);
	if (board[y][x] == '0') {
		for (char c = '1'; c <= '9'; ++c) {
            // if (end == true) return;
			board[y][x] = c;
			if (is_right_board(x, y, board)) {
				back_tracking(next_x, next_y, board, ans);
			}
			board[y][x] = '0';
		}
	} else {
		back_tracking(next_x, next_y, board, ans);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<string>	board(9);
	for (int i = 0; i < 9; ++i) {
		cin >> board[i];
	}
	vector<string>	ans;
	back_tracking(0, 0, board, ans);
	for (int i = 0; i < 9; ++i) {
		cout << ans[i] << '\n';
	}
}