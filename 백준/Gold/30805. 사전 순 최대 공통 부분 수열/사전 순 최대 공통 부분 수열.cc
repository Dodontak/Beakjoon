#include <iostream>
#include <vector>

using namespace std;

int	get_largest_num(int idx1, int idx2, const vector<int> &vec1, const vector<int> &vec2) {
	int	largest_num = 0;
	for (int i = idx1; i < vec1.size(); ++i) {
		for (int j = idx2; j < vec2.size(); ++j) {
			if (vec1[i] == vec2[j] && vec1[i] > largest_num) {
				largest_num = vec1[i];
			}
		}	
	}
	return (largest_num);
}

int	find_idx(int idx, int num, const vector<int> &vec) {
	for (int i = idx; i < vec.size(); ++i) {
		if (vec[i] == num) return i;
	}
	return (-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	n;
	cin >> n;
	vector<int>	vec1(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec1[i];
	}
	cin >> n;
	vector<int>	vec2(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec2[i];
	}
	vector<int>	ans;
	int	idx1 = 0;
	int	idx2 = 0;
	while (1)
	{
		int num = get_largest_num(idx1, idx2, vec1, vec2);
		if (num == 0) break;
		ans.push_back(num);
		idx1 = find_idx(idx1, num, vec1) + 1;
		idx2 = find_idx(idx2, num, vec2) + 1;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}
