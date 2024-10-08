#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 2000000000

using namespace std;

typedef pair<int, int> pii;

vector<int>	get_dists(int start, vector<int> &route, const vector<vector<int> > &links) {
	priority_queue<pii, vector<pii>, greater<pii> >	pq;
	vector<int>	dists(links.size(), INF);
	pq.push(make_pair(0, start));
	dists[start] = 0;
	while (!pq.empty()) {
		int	cur_node = pq.top().second;
		int	cur_dist = pq.top().first;
		pq.pop();
		if (dists[cur_node] != cur_dist) continue;
		for (int linked_node = 1; linked_node < links.size(); ++linked_node) {
			int	linked_dist = links[cur_node][linked_node];
			if (linked_dist == INF) continue;
			int	new_dist = linked_dist + cur_dist;
			if (new_dist < dists[linked_node]) {
				dists[linked_node] = new_dist;
				route[linked_node] = cur_node;
				pq.push(make_pair(new_dist, linked_node));
			}
		}
	}
	return (dists);
}

void print_route(int end_node, int start_node, const vector<int> &route) {
    stack<int> s;
    int cur_node = end_node;
    while (cur_node != start_node) {
        s.push(cur_node);
        cur_node = route[cur_node];
    }
    s.push(start_node);
    cout << s.size() << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n, m;
	cin >> n >> m;
	vector<vector<int> >	links(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= m; ++i) {
		int	st, ed, dist;
		cin >> st >> ed >> dist;
		links[st][ed] = min(links[st][ed], dist);
	}
	int	start, end;
	cin >> start >> end;
	vector<int>	route(n + 1, -1);
	vector<int>	dists = get_dists(start, route, links);
	cout << dists[end] << '\n';
    print_route(end, start, route);
}
