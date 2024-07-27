#include <iostream>
#include <vector>
#include <queue>
#define	INF	2147483647

using namespace std;

typedef	pair<int, int>	pii;
typedef priority_queue<pii, vector<pii>, greater<pii> >	PQ;

int	dijkstra(int start, int end, const vector<vector<pii> > &links) {
	PQ	pq;
	pq.push(make_pair(0, start));
	vector<int>	dists(links.size(), INF);
	dists[start] = 0;
	while (!pq.empty()) {
		int	cur_node = pq.top().second;
		int	cur_dist = pq.top().first;
		pq.pop();
		if (cur_node == end) break;
		if (cur_dist != dists[cur_node]) continue;
		for (int i = 0; i < links[cur_node].size(); ++i) {
			int	linked_node = links[cur_node][i].second;
			int	link_dist = links[cur_node][i].first;
			int	new_dist = cur_dist + link_dist;
			if (new_dist < dists[linked_node]) {
				dists[linked_node] = new_dist;
				pq.push(make_pair(new_dist, linked_node));
			}
		}
	}
	return (dists[end]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n, m;
	cin >> n >> m;
	vector<vector<pii> >	links(n + 1);
	for (int i = 0; i < m; ++i) {
		int	st, ed, dist;
		cin >> st >> ed >> dist;
		links[st].push_back(make_pair(dist, ed));
	}
	int	start, end;
	cin >> start >> end;
	cout << dijkstra(start, end, links) << endl;
}
