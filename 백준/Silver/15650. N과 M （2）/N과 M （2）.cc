#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void	print(const vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << '\n';
}

void	dfs(int i, int n, int m, vector<int> vec)
{
	vec.push_back(i);
	if (vec.size() == m) {
		print(vec);
		return;
	}
	while (i++ < n) {
		dfs(i, n, m, vec);
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	int	m; cin >> m;
	vector<int>	vec;
	for (int i = 1, end = n - m + 1; i <= end; ++i) {
		dfs(i, n, m, vec);
	}
}