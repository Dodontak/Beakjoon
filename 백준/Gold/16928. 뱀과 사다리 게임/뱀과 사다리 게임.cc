#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool	is_can_go(int idx, const vector<bool>& visit)
{
	if (idx <= 0 || idx > 100) return (false);
	if (visit[idx] == true) return (false);
	return (true);
}

int	bfs(vector<bool>& visit, const vector<int>& ladder)
{
	queue<pair<int, int> >	q;
	q.push(make_pair(1, 0));
	visit[1] = true;
	int	count;
	int	idx;
	while (!q.empty()) {
		int	idx = q.front().first;
		int	count = q.front().second;
		if (idx == 100) return (count);
		for (int i = 1; i <= 6; ++i) {
			if (is_can_go(idx + i, visit)) {
				visit[idx + i] = true;
				if (ladder[idx + i] != -1) {
					if (is_can_go(ladder[idx + i], visit)) {
						visit[ladder[idx + i]] = true;
						q.push(make_pair(ladder[idx + i], count + 1));
					}
				} else {
					q.push(make_pair(idx + i, count + 1));
				}
			}
		}
		q.pop();
	}
	return (-1);
}

int	main()
{
	int	n; cin >> n;
	int	m; cin >> m;
	vector<bool>	visit(101, false);
	vector<int>		ladder(101, -1);
	while (n--) {
		int	st, ed;
		cin >> st >> ed;
		ladder[st] = ed;
	}
	while (m--) {
		int	st, ed;
		cin >> st >> ed;
		ladder[st] = ed;
	}
	cout << bfs(visit, ladder) << endl;
}
