#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int	n;

pair<int, int>	bfs(int st_node, const vector<pair<int, int> >* link)
{
	vector<pair<int, int> >	dp(n + 1);
	vector<bool>			visit(n + 1, false);
	queue<pair<int, int> >	q;
	q.push(make_pair(st_node, 0));//노드번호, 거리
	visit[st_node] = true;
	dp[st_node].first = st_node;
	dp[st_node].second = 0;
	int	node;
	int	len;
	int	max_len = 0;
	int	max_len_node = st_node;
	while (!q.empty()) {
		node = q.front().first;
		len = q.front().second;
		//이 노드와 연결된 점들 중에서 아직 방문하지 않은 곳을 방문 목록에 추가하고, dp에 내 길이 + 링크 길이 기록한다.
		for (size_t i = 0; i < link[node].size(); ++i) {
			int	ed = link[node][i].first;
			int	link_len = link[node][i].second;
			if (!visit[ed]) {
				visit[ed] = true;
				dp[ed].first = ed;
				dp[ed].second = len + link_len;
				q.push(make_pair(ed, dp[ed].second));
				if (max_len < dp[ed].second) {
					max_len = dp[ed].second;
					max_len_node = ed;
				}
			}
		}
		q.pop();
	}
	return (make_pair(max_len_node, max_len));
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<pair<int, int> >	node[n + 1];//페어<도착지, 길이>
	int	parent, child, len;
	for (int i = 1; i < n; ++i) {
		cin >> parent >> child >> len;
		node[parent].push_back(make_pair(child, len));
		node[child].push_back(make_pair(parent, len));
	}
	int	far_node = bfs(1, node).first;
	int	ans = bfs(far_node, node).second;
	cout << ans << endl;
}