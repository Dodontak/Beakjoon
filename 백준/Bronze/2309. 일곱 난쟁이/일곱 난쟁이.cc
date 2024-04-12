#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	print(const vector<int>& arr, size_t a, size_t b)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (i == a || i == b)
			continue;
		cout << arr[i] << '\n';
	}
}

void	test(const vector<int>& arr, size_t a, size_t b)
{
	int sum = 0;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (i == a || i == b)
			continue;
		sum += arr[i];
	}
	if (sum == 100)
	{
		print(arr, a, b);
		return ;
	}
	if (b == arr.size() - 1)
		test(arr, a + 1, a + 2);
	else
		test(arr, a, b + 1);
}

int	main()
{
	vector<int> arr;
	int	n;
	for (int i = 0; i < 9; i++)
	{
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	test(arr, 0, 1);
}
