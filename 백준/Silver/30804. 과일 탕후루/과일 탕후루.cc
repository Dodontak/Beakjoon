#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	vector<int> fruits(10, 0);
	int left = 0;
	int right = 0;
	int types = 0;
	int ans = 0;
	while (right < n)
	{
		int fruit = vec[right];
		if (fruits[fruit]++ == 0)
		{
			types++;
		}
		while (types > 2)
		{
			fruit = vec[left];
			if (--fruits[fruit] == 0)
			{
				types--;
			}
			++left;
		}
		ans = max(ans, right - left + 1);
		++right;
	}
	cout << ans << endl;
}
