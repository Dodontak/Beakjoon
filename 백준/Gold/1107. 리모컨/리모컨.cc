#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int	abs(int a)
{
	return (a > 0 ? a : -a);
}

int	intlen(int n)
{
	int	count = 0;
	if (n == 0) return (1);
	while (n) {
		n /= 10;
		++count;
	}
	return (count);
}

bool	is_num_usable(int n, const vector<bool>& usable)
{
	if (usable[n % 10] == false) return (false);
	while (n) {
		if (usable[n % 10] == false) return (false);
		n /= 10;
	}
	return (true);
}

int	get_count(int channer, int target)
{
	return (intlen(channer) + abs(target - channer));
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int	target; cin >> target;
	int	minimum = abs(target - 100);
	int	m; cin >> m;
	vector<bool>	usable(10, true);
	for (int i = 0; i < m; ++i) {
		int	broken; cin >> broken;
		usable[broken] = false;
	}
	if (m == 10) {
		cout << minimum << '\n';
		return (0);
	}

	int	upper = 1000000;
	for (int i = target; i <= 1000000; ++i) {
		if (is_num_usable(i, usable)) {
			upper = i;
			break;
		}
	}
	int	lower = 0;
	for (int i = target; i >= 0; --i) {
		if (is_num_usable(i, usable)) {
			lower = i;
			break;
		}
	}
	if (is_num_usable(upper, usable)) {
		minimum = min(get_count(upper, target), minimum);
	}
	if (is_num_usable(lower, usable)) {
		minimum = min(get_count(lower, target), minimum);
	}
	cout << minimum << '\n';
}

