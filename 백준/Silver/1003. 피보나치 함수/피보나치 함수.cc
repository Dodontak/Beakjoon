#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int> >	dp(41, vector<int>(2, 0));
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (size_t i = 2; i < dp.size(); ++i) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	int	test_case; cin >> test_case;
	int	n;
	while (test_case--) {
		cin >> n;
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
	}
}
