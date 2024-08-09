#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	get_dp_value(int i, int j, const vector<vector<int> > &dp, const vector<pair<int, int> > &apps) {
	int	prev_memory = dp[i - 1][j];
	int	app_memory = apps[i].first;
	int	app_cost = apps[i].second;
	if (j - app_cost < 0) return (prev_memory);
	return (max(dp[i - 1][j - app_cost] + app_memory, prev_memory));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n, m;
	cin >> n >> m;
	vector<pair<int, int> >	apps(n + 1);
	int	max_cost = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> apps[i].first;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> apps[i].second;
		max_cost += apps[i].second;
	}
	
	vector<vector<int> >	dp(n + 1, vector<int>(max_cost + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= max_cost; ++j) {
			dp[i][j] = get_dp_value(i, j, dp, apps);
		}
	}
	cout << lower_bound(dp[n].begin(), dp[n].end(), m) - dp[n].begin() << endl;;
}
