#include <iostream>
#include <vector>

using namespace std;

void	print_line(int idx, const int& n) {
	for (int i = idx + 1; i < n; ++i) {
		cout << ' ';
	}
	for (int i = 0; i <= idx; ++i) {
		cout << '*';
	}
	for (int i = 0; i < idx; ++i) {
		cout << '*';
	}
	cout << '\n';
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	for (int i = 0; i < n; ++i) {
		print_line(i, n);
	}
	for (int i = n - 2; i >= 0; --i) {
		print_line(i, n);
	}
}
