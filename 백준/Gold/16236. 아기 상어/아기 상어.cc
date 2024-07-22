#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int	dx[] = {1, 0, -1, 0};
int	dy[] = {0, 1, 0, -1};

typedef pair<int, int>	pii;

class Pos {
public:
	int x;
	int y;
	Pos() : x(0), y(0) {}
	Pos(int _x, int _y) : x(_x), y(_y) {}
	bool	operator<(const Pos& pos) const {
		if (y < pos.y) return true;
		if (y == pos.y) {
			if (x < pos.x) return true;
		}
		return false;
	}
};

class Shark {
public:
	Pos	pos;
	int	size;
	int	eat_count;
	Shark() : pos(Pos(0, 0)), size(2), eat_count(0) {}
	void	eat(int x, int y) {
		++eat_count;
		pos.x = x;
		pos.y = y;
		if (eat_count == size) {
			eat_count = 0;
			++size;
		}
	}
};


bool	is_can_go(int x, int y, int size, const vector<vector<int> > &vec, const vector<vector<bool> > &visit) {
	if (x < 0 || x >= vec[0].size() || y < 0 || y >= vec.size()) return false;
	if (visit[y][x] == true) return false;
	if (size < vec[y][x]) return false;
	return true;
}

int	bfs(Shark &shark, vector<vector<int> > &vec) {
	priority_queue<pair<int, Pos>, vector<pair<int, Pos> >, greater<pair<int, Pos> > >	pq;
	vector<vector<bool> >	visit(vec.size(), vector<bool>(vec.size(), false));

	pq.push(make_pair(0, shark.pos));
	visit[shark.pos.y][shark.pos.x] = true;
	while (!pq.empty()) {
		Pos	cur_pos = pq.top().second;
		int	cur_dist = pq.top().first;
		pq.pop();
		if (vec[cur_pos.y][cur_pos.x] != 0 && vec[cur_pos.y][cur_pos.x] < shark.size) {
			vec[cur_pos.y][cur_pos.x] = 0;
			shark.eat(cur_pos.x, cur_pos.y);
			return cur_dist;
		}
		for (int i = 0; i < 4; ++i) {
			Pos	next_pos(cur_pos.x + dx[i], cur_pos.y + dy[i]);
			int	next_dist = cur_dist + 1;
			if (is_can_go(next_pos.x, next_pos.y, shark.size, vec, visit)) {
				pq.push(make_pair(next_dist, next_pos));
				visit[next_pos.y][next_pos.x] = true;
			}
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n;
	cin >> n;
	Shark	shark;
	vector<vector<int> >	vec(n, vector<int>(n));
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> vec[y][x];
			if (vec[y][x] == 9) {
				shark.pos.x = x;
				shark.pos.y = y;
				vec[y][x] = 0;
			}
		}	
	}
	int	time = 0;
	while (1) {
		int	a = bfs(shark, vec);
		if (a == -1) break;
		time += a;
	}
	cout << time << endl;
}
