#include <iostream>
#include <vector>

using namespace std;

long long get_length(const vector<int> &tree, int h)
{
	long long len = 0;
	for (int i = 0; i < tree.size(); ++i)
		if (tree[i] > h)
			len += tree[i] - h;
	return len;
}

int get_saw_heitht(const int &max_len, const long long &want_length, const vector<int> &tree)
{
	int st = 0;
	int ed = max_len;
	int ans;
	while (st <= ed)
	{
		int mid = ((long long)st + ed) / 2;
		long long len = get_length(tree, mid);
		if (len >= want_length)
		{
			ans = mid;
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> tree(n);
	int max_len = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> tree[i];
		max_len = max(max_len, tree[i]);
	}
	cout << get_saw_heitht(max_len, m, tree) << endl;
}