#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n, m;
	cin >> n >> m;
	vector<int>	in_degree(n + 1, 0);
	vector<vector<int> >	graph(n + 1);
	for (int i = 0; i < m; ++i) {
		int	small, big;
		cin >> small >> big;
		graph[small].push_back(big);
		++in_degree[big];
	}
	queue<int>	q;
	queue<int>	ans;
	for (int i = 1; i <= n; ++i) {
		if (in_degree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int	cur_student = q.front();
		q.pop();
		ans.push(cur_student);
		while (!graph[cur_student].empty()) {
			int	taller_student = graph[cur_student].back();
			graph[cur_student].pop_back();
			if (--in_degree[taller_student] == 0) {
				q.push(taller_student);
			}
		}
	}
	while (!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop();
	}
	cout << endl;
}
