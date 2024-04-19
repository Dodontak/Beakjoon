#include <iostream>
#include <vector>

using namespace std;

void	print(int xst, int yst, int xed, int yed, const vector<vector<int> >& dp)
{
	cout << dp[xed][yed] - dp[xed][yst - 1] - dp[xst - 1][yed] + dp[xst - 1][yst - 1] << '\n';
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	int	m; cin >> m;
	vector<vector<int> >	vec(n + 1, vector<int>(n + 1));
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			cin >> vec[x][y];
		}
	}
	vector<vector<int> >	dp(n + 1, vector<int>(n + 1, 0));
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			dp[x][y] = dp[x - 1][y] + dp[x][y - 1] - dp[x - 1][y - 1] + vec[x][y];
		}
	}
	while (m--) {
		int xst, yst, xed, yed;
		cin >> xst >> yst >> xed >> yed;
		print(xst, yst, xed, yed, dp);
	}
}
