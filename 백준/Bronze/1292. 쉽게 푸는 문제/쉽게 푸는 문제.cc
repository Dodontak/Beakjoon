#include <iostream>
#include <vector>

using namespace std;

int	main()
{
	vector<int>	arr;

	int	a, b;
	cin >> a >> b;
	for (int i = 1; i <= b; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			arr.push_back(i);
		}
	}
	int	sum = 0;
	for (int i = a - 1; i < b; ++i)
	{
		sum += arr[i];
	}
	cout << sum << endl;
}
