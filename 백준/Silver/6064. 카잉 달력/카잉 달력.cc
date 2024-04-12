#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a == 0)return b;
	return gcd(b%a, a);
}

int get_same(const vector<int>& small, const vector<int>& big)
{
	for (size_t i = 0; i < small.size(); ++i) {
		if (binary_search(big.begin(), big.end(), small[i]) == true) {
			return (small[i]);
		}
	}
	return (-1);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int	t; cin >> t;
	while (t--) {
		int	m, n, x, y;
		cin >> m >> n >> x >> y;
		int	scm = m * n / gcd(m, n);
		vector<int>	xlist(scm / m);
		for (size_t i = 0; i < xlist.size(); ++i) {
			xlist[i] = i * m + x;	
		}
		vector<int>	ylist(scm / n);
		for (size_t i = 0; i < ylist.size(); ++i) {
			ylist[i] = i * n + y;
		}
		if (xlist.size() < ylist.size()) {
			cout << get_same(xlist, ylist) << '\n';
		} else {
			cout << get_same(ylist, xlist) << '\n';
		}
	}
}