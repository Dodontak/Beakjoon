#include <iostream>
#include <vector>
#include <algorithm>

#define INF 210000000000

using namespace std;

long long long_abs(long long num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n;
	cin >> n;
	vector<long long>	vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	long long	a, b, c;
	long long ans = INF;
	for (int selected = 0; selected < vec.size(); ++selected) {
		int	left = 0;
		int	right = vec.size() - 1;
		while (left < right && right >= 0 && left < vec.size()) {
			if (right == selected) {
				--right;
				continue;
			} else if (left == selected) {
				++left;
				continue;
			}
			long long sum = vec[selected] + vec[left] + vec[right];
			if (long_abs(sum) < ans) {
				ans = long_abs(sum);
				a = vec[selected];
				b = vec[left];
				c = vec[right];
			}
			if (sum < 0) {
				++left;
			} else {
				--right;
			}
		}
	}
	vector<long long>	result;
	result.push_back(a);
	result.push_back(b);
	result.push_back(c);
	sort(result.begin(), result.end());
	cout << result[0] << ' ' << result[1] << ' ' << result[2] << endl;
}
