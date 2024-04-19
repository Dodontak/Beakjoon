#include <iostream>
#include <vector>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	int	k; cin >> k;
	vector<pair<int, int> >	vec(n + 1, make_pair(0, 0));
	for (int i = 1; i <= n; ++i) {
		cin >> vec[i].first >> vec[i].second;
	}
	vector<vector<int> >	dp(n + 1, vector<int>(k + 1, 0));
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (j - vec[i].first < 0) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i].first] + vec[i].second);
			}
		}
	}
	cout << dp[n][k] << endl;
}
