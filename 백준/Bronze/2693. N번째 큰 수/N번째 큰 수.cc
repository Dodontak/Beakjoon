#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	main()
{
	int	t;
	cin >> t;
	while (t--)
	{
		vector<int> arr;
		int	n;
		for (int i = 0; i < 10; i++)
		{
			cin >> n;
			arr.push_back(n);
		}
		sort(arr.rbegin(), arr.rend());
		cout << arr[2] << endl;
	}
}
