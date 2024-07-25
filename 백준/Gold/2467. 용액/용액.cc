#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int	n;
	cin >> n;
	vector<int>	vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	int	left = 0;
	int right = vec.size() - 1;
	int	ans = 2000000001;
	pair<int, int>	p;
	while (left < right) {
		int	a = vec[left];
		int	b = vec[right];
		int	sum = a + b;
		if (abs(sum) < ans) {
			ans = abs(sum);
			p.first = left;
			p.second = right;
		}
		if (sum < 0) {
			left++;
		} else {
			right--;
		}
	}
	cout << vec[p.first] << ' ' << vec[p.second] << endl;
}
