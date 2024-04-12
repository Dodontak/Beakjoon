#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main()
{
	int	n; cin >> n;
	int	time;
	vector<int>	vec;
	for (int i = 0; i < n; ++i) {
		cin >> time;
		vec.push_back(time);
	}
	sort(vec.begin(), vec.end());
	int	sum = 0;
	int	pi = 0;
	for (size_t i = 0; i < vec.size(); ++i) {
		pi += vec[i];
		sum += pi;
	}
	cout << sum << endl;
}
