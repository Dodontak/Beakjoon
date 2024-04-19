#include <iostream>
#include <vector>

using namespace std;

bool	is_wrong(const vector<int>& queens, const int& n)
{
	for (int i = 0; i < n; ++i) {
		if (queens[i] == queens[n]) {
			return (true);
		} else if (i + queens[i] == n + queens[n] || i - queens[i] == n - queens[n]) {
			return (true);
		}
	}
	return (false);
}



// void	print(const vector<int>& queens) {
// 	for (size_t i = 0; i < queens.size(); ++i) {
// 		for (size_t j = 0; j < queens.size(); ++j) {
// 			if (j == queens[i]) {
// 				cout << 'X';
// 			} else {
// 				cout << '.';
// 			}
// 		}
// 		cout << '\n';
// 	}
// }

int	dfs(vector<int>& queens, size_t n)
{
	static int	count;
	if (n == queens.size()) {
		++count;
		return (count);
	}
	for (int i = 0; i < queens.size(); ++i) {
		queens[n] = i;
		if (!is_wrong(queens, n)) {
			dfs(queens, n + 1);
		}
	}
	return (count);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	size;
	cin >> size;
	vector<int>	queens(size);
	cout << dfs(queens, 0) << endl;
}
