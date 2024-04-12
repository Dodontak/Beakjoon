#include <iostream>
#include <vector>

using namespace std;

void	spread(vector<vector<bool> >& vec, int x, int y)
{
	if (x < 0 || x >= (int)vec[0].size() || y < 0 || y >= (int)vec.size()) {
		return;
	} else if (vec[y][x] == false) {
		return;
	} 
	vec[y][x] = false;
	spread(vec, x + 1, y);
	spread(vec, x - 1, y);
	spread(vec, x, y + 1);
	spread(vec, x, y - 1);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	t; cin >> t;
	while (t--) {
		int	m, n, k; cin >> m >> n >> k;
		int	count = 0;
		vector<vector<bool> >	vec(n, vector<bool>(m, 0));
		while (k--) {
			int	x, y; cin >> x >> y;
			vec[y][x] = true;
		}
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < m; ++x) {
				if (vec[y][x] == true) {
					++count;
					spread(vec, x, y);
				}
			}
		}
		cout << count << endl;
	}
}
