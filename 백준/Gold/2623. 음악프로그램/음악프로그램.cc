#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n, m;
	cin >> n >> m;
	vector<vector<int> >	vec(n + 1);
	vector<int>	in_degree(n + 1, 0);
	vector<int>	singer_list(n);
	for (int i = 1; i <= m; ++i) {
		int	num_of_singer;
		cin >> num_of_singer;
		for (int j = 0; j < num_of_singer; ++j) {
			cin >> singer_list[j];
		}
		for (int j = 0; j < num_of_singer; ++j) {
			if (j != num_of_singer - 1) vec[singer_list[j]].push_back(singer_list[j + 1]);
			if (j != 0) ++in_degree[singer_list[j]];
		}
	}
	queue<int>	q;
	queue<int>	ans;
	for (int i = 1; i <= n; ++i) {
		if (in_degree[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int	num = q.front();
		q.pop();
		while (!vec[num].empty()) {
			int	next_singer = vec[num].back();
			vec[num].pop_back();
			if (--in_degree[next_singer] == 0) q.push(next_singer);
		}
		ans.push(num);
	}
	if (ans.size() != n) {
		cout << "0\n";
	} else {
		while (!ans.empty()) {
			cout << ans.front() << '\n';
			ans.pop();
		}	
	}
}
