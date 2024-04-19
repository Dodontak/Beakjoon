#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define INF 10000000

using namespace std;

typedef	priority_queue<int, vector<int>, greater<int> > linkpq;
typedef	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqueue;
//pair<weight, node> 가중치가 작은게 더 우선. 가중치 같으면 노드 번호 낮은게 우선.

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	v; cin >> v;
	int	e; cin >> e;
	int	st_node; cin >> st_node;
	vector<vector<pair<int, int> > >	link(v + 1, vector<pair<int, int> >());
	vector<int>	weight(v + 1, INF);
	for (int i = 0; i < e; ++i) {
		int	st, ed, w;
		cin >> st >> ed >> w;
		link[st].push_back(make_pair(ed, w));
	}
	pqueue	pq;
	weight[st_node] = 0;
	pq.push(make_pair(weight[st_node], st_node));
	int	cur_node, cur_weight;
	while (!pq.empty()) {
		cur_node = pq.top().second;
		cur_weight = pq.top().first;
		//현재 노드와 연결된 노드들 중 갱신될 애들은 큐에 올림.
		for (size_t i = 0; i < link[cur_node].size(); ++i) {//현재 노드에 연결된 애들 순회
			int	linked_node = link[cur_node][i].first;
			int	link_weight = link[cur_node][i].second;
			if (cur_weight + link_weight < weight[linked_node]) {//현재 연결된 경로의 weight보다 지금 확인한 경로가 weight가 작으면
				weight[linked_node] = link_weight + cur_weight;//weight 갱신함
				pq.push(make_pair(weight[linked_node], linked_node));//방문 목록에 추가함
			}
		}
		pq.pop();
	}
	for (size_t i = 1; i < weight.size(); ++i) {
		if (weight[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << weight[i] << '\n';
		}
	}
}