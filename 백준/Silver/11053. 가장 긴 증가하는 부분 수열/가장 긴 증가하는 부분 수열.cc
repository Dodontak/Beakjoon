#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	vector<int>	vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	vector<int>	dp(n, 1);
	int	max_len = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (vec[j] < vec[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				max_len = max(dp[i], max_len);
			}
		}
	}
	cout << max_len << '\n';
}
