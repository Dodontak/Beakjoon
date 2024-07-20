#include <iostream>
#include <vector>

#define	MOD 1000000007

using namespace std;

long long	power(long long num, long long p) {
	long long	tmp;
	if (p == 1) {
		return (num);
	}
	if (p % 2 == 1) {
		tmp = power(num, p / 2);
		return ((((tmp * tmp) % MOD) * num) % MOD);
	} else {
		tmp = power(num, p / 2);
		return ((tmp * tmp) % MOD);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	m; cin >> m;

	vector<pair<long long, long long> >	dices(m);
	long long	sides;
	long long	sides_sum;
	long long	sum = 0;
	for (int i = 0; i < m; ++i) {
		cin >> sides;//주사위 면 수
		cin >> sides_sum;//모든 면의 총 합
		sum += (sides_sum * power(sides, MOD - 2)) % MOD;
		sum %= MOD;
	}
	cout << sum << endl;
}
