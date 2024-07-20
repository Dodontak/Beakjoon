#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX 100000000

using namespace std;

typedef priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >	PQ;

int	get_ans(int start_node, int range, const vector<int> &value, const vector<vector<int> > &links) {
	PQ	pq;
	int	sum = 0;
	vector<bool>	visit(value.size(), false);
	pq.push(make_pair(0, start_node));
	while (!pq.empty()) {
		int	cur_node = pq.top().second;
		int	cur_dist = pq.top().first;
		pq.pop();
		if (visit[cur_node] == true) continue;
		visit[cur_node] = true;
		sum += value[cur_node];
		for (int linked_node = 1; linked_node < value.size(); ++linked_node) {
			if (visit[linked_node] == true) continue;
			int	linked_dist = links[cur_node][linked_node];
			if (cur_dist + linked_dist > range) continue;
			pq.push(make_pair(cur_dist + linked_dist, linked_node));
		}
	}
	return (sum);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n, range, r;
	cin >> n >> range >> r;
	vector<vector<int> >	links(n + 1, vector<int>(n + 1, MAX));
	vector<int>	value(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> value[i];
	}
	for (int i = 0; i < r; ++i) {
		int	st, ed, dist;
		cin >> st >> ed >> dist;
		links[st][ed] = dist;
		links[ed][st] = dist;
	}
	int	ans = 0;
	for (int i = 1; i <= n; ++i) {
		int a = get_ans(i, range, value, links);
		ans = max(ans, a);
	}
	cout << ans << endl;
}
