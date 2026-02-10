#include <iostream>
#include <vector>
#include <queue>

#define	INF	2147483647

using namespace std;

typedef pair<int, int> PII;
typedef priority_queue<PII, vector<PII>, greater<PII> >	PQ;

int dijkstra(int start, int end, const vector<vector<PII>>& links)
{
	PQ pq;
	pq.push(make_pair(0, start));
	vector<int> dists(links.size(), INF);
	dists[start] = 0;
	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		if (cur_node == end) return cur_dist;
		if (cur_dist != dists[cur_node]) continue;
		for (int i = 0; i < links[cur_node].size(); i++)
		{
			int next_node = links[cur_node][i].first;
			int next_dist = links[cur_node][i].second + dists[cur_node];
			if (next_dist < dists[next_node])
			{
				dists[next_node] = next_dist;
				pq.push(make_pair(next_dist, next_node));
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<PII>> links(n + 1);
	for (int i = 0; i < m; i++)
	{
		int st, ed, cost;
		cin >> st >> ed >> cost;
		links[st].push_back(make_pair(ed, cost));
	}
	int start, end;
	cin >> start >> end;
	cout << dijkstra(start, end, links) << endl;
}
