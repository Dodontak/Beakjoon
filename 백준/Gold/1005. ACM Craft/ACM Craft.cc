#include <iostream>
#include <vector>

using namespace std;

int	t, n, k, w;
vector<int>	build_time(1001);
vector<bool>	is_built(1001);

void	set_built() {
	for (int i = 0; i <= n; ++i) {
		is_built[i] = false;
	}
}

void	recursion(int building, const vector<vector<int> > &build_tree) {
	for (int i = 0; i < build_tree[building].size(); ++i) {
		if (is_built[build_tree[building][i]] == true) continue;
		recursion(build_tree[building][i], build_tree);
	}
	int	max_build_time = 0;
	for (int i = 0; i < build_tree[building].size(); ++i) {
		max_build_time = max(max_build_time, build_time[build_tree[building][i]]);
	}
	build_time[building] += max_build_time;
	is_built[building] = true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		set_built();
		for (int i = 1; i <= n; ++i) {
			cin >> build_time[i];
		}
		vector<vector<int> >	build_tree(n + 1);
		for (int i = 0; i < k; ++i) {
			int	a, b;
			cin >> a >> b;
			build_tree[b].push_back(a);
		}
		cin >> w;
		recursion(w, build_tree);
		cout << build_time[w] << '\n';
	}
}