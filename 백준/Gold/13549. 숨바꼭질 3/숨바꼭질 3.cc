#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int	bfs(int n, vector<bool>& visit, const int& k)
{
	queue<pair<int, int> >	q1;
	queue<pair<int, int> >	q2;
	q1.push(make_pair(n, 0));
	visit[n] = true;
	int	pos;
	int	count;
	while (!q1.empty() || !q2.empty()) {
		if (!q1.empty()) {
			pos = q1.front().first;
			count = q1.front().second;
			q1.pop();
		} else {
			pos = q2.front().first;
			count = q2.front().second;
			q2.pop();
		}
		if (pos == k) {
			return (count);
		}
		if (pos * 2 <= 200000 && visit[pos * 2] == false) {
			if (pos * 2 == k) return (count);
			visit[pos * 2] = true;
			q1.push(make_pair(pos * 2, count));
		}
		if (pos - 1 >= 0 && visit[pos - 1] == false) {
			if (pos - 1 == k) return (count + 1);
			visit[pos - 1] = true;
			q2.push(make_pair(pos - 1, count + 1));
		}
		if (pos + 1 <= 200000 && visit[pos + 1] == false) {
			if (pos + 1 == k) return (count + 1);
			visit[pos + 1] = true;
			q2.push(make_pair(pos + 1, count + 1));
		}
	}
	return (-1);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	int	k; cin >> k;
	vector<bool>	visit(200001, false);
	cout << bfs(n, visit, k) << endl;
}
