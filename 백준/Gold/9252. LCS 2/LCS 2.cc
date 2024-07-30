#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string	str1, str2;
	cin >> str1 >> str2;
	vector<vector<int> >	vec(str1.size() + 1, vector<int>(str2.size() + 1, 0));
	for (int i = 0; i < str1.size(); ++i) {
		for (int j = 0; j < str2.size(); ++j) {
			if (str1[i] == str2[j]) {
				vec[i + 1][j + 1] = vec[i][j] + 1;
			} else {
				vec[i + 1][j + 1] = max(vec[i + 1][j], vec[i][j + 1]);
			}
		}
	}
	stack<char>	ans;
	int	max_len = vec.back().back();
	int	y = str1.size();
	int	x = str2.size();
	while (x > 0 && y > 0) {
		if (vec[y][x] == vec[y][x - 1]) {
			x--;
		} else if (vec[y][x] == vec[y - 1][x]) {
			y--;
		} else if (vec[y][x] - 1 == vec[y - 1][x - 1]) {
			ans.push(str2[x - 1]);
			x--;
			y--;
		}
	}
	cout << vec.back().back() << endl;
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	cout << endl;
}