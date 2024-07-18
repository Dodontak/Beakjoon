#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void	print_laboratory(const vector<vector<int> > &laboratory)
{
	for (int i = 0; i < laboratory.size(); i++) {
		for (int j = 0; j < laboratory[0].size(); j++) {
			cout << laboratory[i][j] << ' ';
		}
		cout << endl;
	}
}

int count_safe_area(const vector<vector<int> > &laboratory)
{
	int count = 0;
	for (int i = 0; i < laboratory.size(); i++)
	{
		for (int j = 0; j < laboratory[i].size(); j++)
		{
			if (laboratory[i][j] == 0)
			{
				count++;
			}
		}
	}
	return count;
}

bool is_can_go(int x, int y, const vector<vector<int> > &laboratory)
{
	int y_len = laboratory.size();
	int x_len = laboratory[0].size();
	if (x < 0 || x >= x_len || y < 0 || y >= y_len)
		return (false);
	if (laboratory[y][x] == 0)
		return (true);
	return (false);
}

int bfs(vector<vector<int> > laboratory)
{
	queue<pair<int, int> > q;
	for (int y = 0; y < laboratory.size(); y++)
	{
		for (int x = 0; x < laboratory[y].size(); x++)
		{
			if (laboratory[y][x] == 2)
			{
				q.push(make_pair(x, y));
			}
		}
	}
	while (!q.empty())
	{
		pair<int, int> virus_pos = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int spreaded_x = virus_pos.first + dx[i];
			int spreaded_y = virus_pos.second + dy[i];
			if (is_can_go(spreaded_x, spreaded_y, laboratory))
			{
				q.push(make_pair(spreaded_x, spreaded_y));
				laboratory[spreaded_y][spreaded_x] = 2;
			}
		}
	}
	return count_safe_area(laboratory);
}

void	get_ans(int &ans, int prev_x, int prev_y, int r, vector<vector<int> > &laboratory)
{
	if (r == 3) {
		ans = max(ans, bfs(laboratory));
		return;
	}
	for (int i = prev_y; i < laboratory.size(); i++) {
		for (int j = (prev_y == i ? prev_x : 0); j < laboratory[0].size(); j++) {
			if (laboratory[i][j] == 0) {
				laboratory[i][j] = 1;
				get_ans(ans, j, i, r + 1, laboratory);
				laboratory[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > laboratory(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> laboratory[i][j];
		}
	}
	int	ans = 0;
	get_ans(ans, 0, 0, 0, laboratory);
	cout << ans << endl;
}
