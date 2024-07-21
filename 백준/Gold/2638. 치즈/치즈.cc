#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
7 9
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0
*/

int	dx[] = {1, 0, -1, 0};
int	dy[] = {0, 1, 0, -1};

bool	is_have_two_surface(int x, int y, const vector<vector<int> > &vec) {
	int	surface_count = 0;
	for (int i = 0; i < 4; ++i) {
		if (vec[y + dy[i]][x + dx[i]] == -1) ++surface_count;
	}
	if (surface_count >= 2) return true;
	return false;
}

int	is_can_spread(int x, int y, const vector<vector<int> > &vec) {
	if (x < 0 || x >= vec[0].size() || y < 0 || y >= vec.size()) return false;
	if (vec[y][x] != 0) return false;
	return true;
}

void	bfs(vector<vector<int> > &vec) {
	queue<pair<int, int> >	q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int	cur_x = q.front().first;
		int	cur_y = q.front().second;
		q.pop();
		if (vec[cur_y][cur_x] == -1) continue;
		vec[cur_y][cur_x] = -1;
		for (int i = 0; i < 4; ++i) {
			if (is_can_spread(cur_x + dx[i], cur_y + dy[i], vec)) {
				q.push(make_pair(cur_x + dx[i], cur_y + dy[i]));
			}
		}
	}
}

vector<vector<int> >	melting(vector<vector<int> > &vec, int &cheese_count) {
	vector<vector<int> >	melted(vec);
	bfs(vec);
	for (int y = 0; y < vec.size(); ++y) {
		for (int x = 0; x < vec[0].size(); ++x) {
			if (melted[y][x] == 1 && is_have_two_surface(x, y, vec)) {
				melted[y][x] = 0;
				--cheese_count;
			}
		}	
	}
	return melted;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n, m;
	cin >> n >> m;
	vector<vector<int> >	vec(n, vector<int>(m));
	int	cheese_count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> vec[i][j];
			if (vec[i][j] == 1) ++cheese_count;
		}
	}
	int	time = 0;
	while (cheese_count) {
		++time;
		vec = melting(vec, cheese_count);
	}
	cout << time << endl;
}
