#include <iostream>
#include <vector>

using namespace std;

bool is_single_color(int x_st, int y_st, int x_ed, int y_ed, const vector<vector<char> > &map)
{
	char color = map[y_st][x_st];
	for (int i = y_st; i <= y_ed; ++i)
		for (int j = x_st; j <= x_ed; ++j)
			if (map[i][j] != color)
				return false;
	return true;
}

void dfs(int x_st, int y_st, int x_ed, int y_ed, const vector<vector<char> > &map, pair<int, int> &count)
{
	if (is_single_color(x_st, y_st, x_ed, y_ed, map))
	{
		if (map[y_st][x_st] == '0')
			count.first++;
		else
			count.second++;
		return;
	}
	int x_mid = (x_st + x_ed) / 2;
	int y_mid = (y_st + y_ed) / 2;
	dfs(x_st, y_st, x_mid, y_mid, map, count);
	dfs(x_mid + 1, y_st, x_ed, y_mid, map, count);
	dfs(x_st, y_mid + 1, x_mid, y_ed, map, count);
	dfs(x_mid + 1, y_mid + 1, x_ed, y_ed, map, count);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<vector<char> > map(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}
	pair<int, int> count(0, 0);
	dfs(0, 0, n - 1, n - 1, map, count);
	cout << count.first << endl;
	cout << count.second << endl;
}
