#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000001

bool	is_can_go(int st, size_t ed, const vector<vector<int> >& link, const vector<int>& prices)
{
	if (link[st][ed] == INF) return (false);
	if (prices[st] + link[st][ed] >= prices[ed]) return (false);
	return (true);
}

struct comp {
	bool	operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return (a.second > b.second);
	}
};

void	print_prices(int n, const vector<vector<int> >& link)//시작점 n 
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, comp>	pq;//노드, 가격
	vector<int>	prices(link.size(), INF);
	pq.push(make_pair(n, 0));
	prices[n] = 0;
	int	cur_node;
	int	cur_price;
	while (!pq.empty()) {
		cur_node = pq.top().first;
		cur_price = pq.top().second;
		pq.pop();
        if (prices[cur_node] != cur_price) continue;
		for (size_t linked_node = 1; linked_node < link.size(); ++linked_node) {
			if (is_can_go(cur_node, linked_node, link, prices)) {
				prices[linked_node] = prices[cur_node] + link[cur_node][linked_node];
				pq.push(make_pair(linked_node, prices[linked_node]));
			}
		}
	}
	for (size_t i = 1; i < prices.size(); ++i) {
		if (prices[i] != INF) cout << prices[i] << ' ';
		else cout << "0 ";
	}
	cout << '\n';
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	int	m; cin >> m;
	vector<vector<int> >	link(n + 1, vector<int>(n + 1, INF));//1~n번 도시까지 있음.
	int	st, ed, price;
	for (int i = 0; i < m; ++i) {
		cin >> st >> ed >> price;
		link[st][ed] = min(link[st][ed], price);
	}
	for (int i = 1; i <= n; ++i) {
		print_prices(i, link);
	}
}
