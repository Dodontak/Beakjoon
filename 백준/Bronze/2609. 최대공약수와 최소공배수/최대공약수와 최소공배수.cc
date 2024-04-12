#include <iostream>
#include <cmath>

using namespace std;

int	main()
{
	int a, b;
	cin >> a >> b;
	int	small, big;
	small = min(a, b);
	big = max(a, b);
	int	yaksu;
	for (int i = 1; i <= small; ++i)
	{
		if (small % i == 0 && big % i == 0)
			yaksu = i;
	}
	cout << yaksu << endl;
	cout << yaksu * (small / yaksu) * (big / yaksu) << endl;
}
