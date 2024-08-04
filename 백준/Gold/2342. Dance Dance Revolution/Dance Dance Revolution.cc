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

vector<vector<int> >	func(const vector<vector<int> > &dp, int next) {
	vector<vector<int> >	out(5, vector<int>(5, INF));
	for (int left = 0 ; left < 5; ++left) {
		for (int right = 0 ; right < 5; ++right) {
			if (dp[left][right] == INF) continue;
			out[left][next] = min(out[left][next], dp[left][right] + calc(right, next));
			out[next][right] = min(out[next][right], dp[left][right] + calc(left, next));
		}
	}
	return out;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int>	vec;
	vector<vector<int> >	dp(5, vector<int>(5, INF));
	dp[0][0] = 0;
	while (1) {
		int	n;
		cin >> n;
		if (n == 0) break;
		dp = func(dp, n);
	}
	int	ans = INF;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ans = min(dp[i][j], ans);
		}
	}
	cout << ans << endl;
}