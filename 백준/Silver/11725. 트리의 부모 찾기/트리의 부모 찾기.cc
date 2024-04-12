#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >	bfs(const vector<set<int> >& link, vector<bool>& visit)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >	out;
	queue<int>	q;
	q.push(1);
	visit[1] = true;
	while (!q.empty()) {
		int	cur = q.front();
		for (set<int>::const_iterator cit = link[cur].cbegin(); cit != link[cur].cend(); ++cit) {
			if (visit[*cit] == false) {
				visit[*cit] = true;
				q.push(*cit);
				out.push(make_pair(*cit, cur));
			}
		}
		q.pop();
	}
	return (out);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	vector<set<int> >	link(n + 1, set<int>());
	for (int i = 0; i < n - 1; ++i) {
		int	st, ed;
		cin >> st >> ed;
		link[st].insert(ed);
		link[ed].insert(st);
	}
	vector<bool>	visit(n + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >	ans;
	ans = bfs(link, visit);
	while (!ans.empty()) {
		cout << ans.top().second << '\n';
		ans.pop();
	}
}
