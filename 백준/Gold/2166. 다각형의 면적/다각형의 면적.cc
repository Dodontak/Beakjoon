#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef	pair<long double, long double>	pdd;

class Pos {
public:
	Pos() : x(0), y(0) {}
	Pos(long double _x, long double _y) : x(_x), y(_y) {}
	long double x;
	long double y;
};

long double	get_tringle_area(const Pos &st, const Pos &a, const Pos &b) {
	Pos	sa(a.x - st.x, a.y - st.y);
	Pos	sb(b.x - st.x, b.y - st.y);
	return (sa.x * sb.y - sb.x * sa.y) / 2.0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n;
	cin >> n;
	vector<Pos>	vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i].x >> vec[i].y;
	}
	long double	sum = 0;
	for (int i = 2; i < n; ++i) {
		sum += get_tringle_area(vec[0], vec[i - 1], vec[i]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(sum) << endl;
}
