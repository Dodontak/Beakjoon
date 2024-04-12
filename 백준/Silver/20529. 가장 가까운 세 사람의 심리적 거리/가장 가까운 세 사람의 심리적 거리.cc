#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int	get_diff(const string& a, const string& b)
{
	int	count = 0;
	for (int i = 0; i < 4; ++i) {
		if (a[i] != b[i]) ++count;
	}
	return (count);
}

int	e_dist(const string& a, const string& b, const string& c)
{
	return (get_diff(a, b) + get_diff(b, c) + get_diff(c, a));
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int	t; cin >> t;
	while (t--) {
		int	n; cin >> n;
		vector<string>	vec(n);
		for (int i = 0; i < n; ++i) {
			cin >> vec[i];
		}
		if (n >= 48) {
			cout << "0\n";
			continue;
		}
		int	minimum_distance = 20;
		for (int i = 0; i < n - 2; ++i) {
			for (int j = i + 1; j < n - 1; ++j) {
				for (int k = j + 1; k < n; ++k) {
					minimum_distance = min(e_dist(vec[i], vec[j], vec[k]), minimum_distance);
				}
			}	
		}
		cout << minimum_distance << '\n';
	}
}