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
	cout << vec.back().back() << endl;
}