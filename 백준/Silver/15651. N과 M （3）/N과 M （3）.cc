#include <iostream>
#include <vector>

using namespace std;

void print_vec(const vector<int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << '\n';
}

void dfs(int idx, int n, int m, vector<int> &vec)
{
	if (idx == m)
	{
		print_vec(vec);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		vec[idx] = i;
		dfs(idx + 1, n, m, vec);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> vec(m, 0);
	dfs(0, n, m, vec);
}