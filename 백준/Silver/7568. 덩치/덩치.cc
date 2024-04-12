#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int	get_rank(const vector<pair<int, int> >& vec, const size_t& idx) {
	int	count = 1;
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i == idx) continue;
		if (vec[i].first > vec[idx].first && vec[i].second > vec[idx].second) ++count;
	}
	return (count);
}

int	main()
{
	size_t	n; cin >> n;
	int	x, y;
	vector<pair<int, int> >	vec;
	for (size_t i = 0; i < n; ++i) {
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}
	for (size_t i = 0; i < n; ++i) {
		cout << get_rank(vec, i) << ' ';
	}
	cout << endl;
}
