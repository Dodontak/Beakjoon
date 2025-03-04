#include <iostream>

using namespace std;

long long	dc(long long a, long long b, long long c)
{
	if (b == 1) {
		return (a % c);
	}
	if (b % 2 == 0) {
		long long res = dc(a, b / 2, c) % c;
		return ((res * res) % c);
	} else {
		long long res = dc(a, (b - 1) / 2, c) % c;
		return ((((res * res) % c) * a) % c);
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long	a, b, c;
	cin >> a >> b >> c;
	cout << dc(a, b, c) << '\n';
}

