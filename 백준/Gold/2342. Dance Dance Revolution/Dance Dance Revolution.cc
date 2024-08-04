#include <iostream>
#include <vector>

#define INF 2100000000

using namespace std;

int	calc(int cur, int next) {
	if (cur == next) return 1;
	else if (cur == 0) return 2;
	else if (cur % 2 == next % 2) return 4;
	else return 3;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int>	vec;
	while (1) {
		int	n;
		cin >> n;
		if (n == 0) break;
		vec.push_back(n);
	}
	vector<vector<vector<int> > >	dp(vec.size() + 1, vector<vector<int> >(5, vector<int>(5, INF)));
	dp[0][0][0] = 0;
	for (int i = 0; i < vec.size(); ++i) {
		int	next = vec[i];
		for (int left = 0 ; left < 5; ++left) {
			for (int right = 0 ; right < 5; ++right) {
				if (dp[i][left][right] == INF) continue;
				dp[i + 1][left][next] = min(dp[i + 1][left][next], dp[i][left][right] + calc(right, next));
				dp[i + 1][next][right] = min(dp[i + 1][next][right], dp[i][left][right] + calc(left, next));
			}
		}
	}
	int	ans = INF;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans = min(dp[vec.size()][i][j], ans);
		}
	}
	cout << ans << endl;
}