#include <iostream>

using namespace std;

int	main()
{
	int	max = 0, cur = 0, cnt = 10;
	int	in, out;
	while (cnt--)
	{
		cin >> out >> in;
		cur = cur - out + in;
		max = cur > max ? cur : max;
	}
	cout << max << '\n';
}
