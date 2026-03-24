#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};

int n;
int m;

class Info
{
public:
	Info(int x_, int y_, int dist_) : x(x_), y(y_), dist(dist_) {}
	int x;
	int y;
	int dist;
};

bool	is_right_idx(const Info& pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.y >= n || pos.x >= m) return (false);
	return (true);
}

bool	is_wall(const Info& pos, const vector<string>& mp)
{
	if (mp[pos.y][pos.x] == '1') return (true);
	return (false);
}

void	wall_bfs(const Info& st, vector<vector<int> >& dists, const vector<string>& mp)
{
	queue<Info>	q;
	q.push(st);
	dists[st.y][st.x] = st.dist;
	while (!q.empty()) {
		Info	pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			Info	next(pos.x + dx[i], pos.y + dy[i], pos.dist + 1);
			if (is_right_idx(next) && !is_wall(next, mp)) {
				if (dists[next.y][next.x] == -1 || next.dist < dists[next.y][next.x]) {
					dists[next.y][next.x] = next.dist;
					q.push(next);
				}
			}
		}
	}
}

void	bfs(const Info& st, const vector<string>& mp)
{
	queue<Info>	q;
	vector<vector<int> >	dists(n, vector<int>(m, -1));
	q.push(st);
	queue<Info>	wall_queue;
	dists[st.y][st.x] = st.dist;
	while (!q.empty()) {
		Info	pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			Info	next(pos.x + dx[i], pos.y + dy[i], pos.dist + 1);
			if (is_right_idx(next) && dists[next.y][next.x] == -1) {
				dists[next.y][next.x] = next.dist;
				if (is_wall(next, mp)) wall_queue.push(next);
				else q.push(next);
			}
		}
	}
	while (!wall_queue.empty()) {
		wall_bfs(wall_queue.front(), dists, mp);
		wall_queue.pop();
	}
	if (dists[n - 1][m - 1] != -1) cout << dists[n - 1][m - 1] << '\n';
	else cout << "-1\n";
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<string>	mp(n);
	for (int i = 0; i < n; ++i) {
		cin >> mp[i];
	}
	bfs(Info(0, 0, 1), mp);
}