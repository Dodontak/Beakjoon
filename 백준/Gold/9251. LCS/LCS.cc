#include <iostream>
#include <string>
#include <vector>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string	a, b;
	cin >> a >> b;
	vector<vector<int> >	dp(b.length() + 1, vector<int>(a.length() + 1, 0));
	for (size_t bi = 0, dpi = 1; bi < b.length(); ++bi, ++dpi) {
		for (size_t aj = 0, dpj = 1; aj < a.length(); ++aj, ++dpj) {
			if (b[bi] == a[aj]) {
				dp[dpi][dpj] = dp[dpi - 1][dpj - 1] + 1;
			} else {
				dp[dpi][dpj] = max(dp[dpi][dpj - 1], dp[dpi - 1][dpj]);
			}
		}	
	}
	cout << dp[b.length()][a.length()] << '\n';
}
