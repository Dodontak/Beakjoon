#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

void	dfs(int cur_student, const vector<int> &select, vector<bool> &is_done, vector<bool> &visit, int &count) {
	visit[cur_student] = true;
	if (visit[select[cur_student]] != true) {
		dfs(select[cur_student], select, is_done, visit, count);
	} else if (is_done[select[cur_student]] == false) {
		++count;
		for (int next = select[cur_student]; next != cur_student; next = select[next]) {
			++count;
		}
	}
	is_done[cur_student] = true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	t;
	cin >> t;
	while (t--) {
		int	n;
		cin >> n;
		vector<int>		select(n + 1);
		vector<bool>	is_done(n + 1, false);
		vector<bool>	visit(n + 1, false);
		int	count = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> select[i];
		}
		for (int i = 1; i <= n; ++i) {
			if (visit[i] == true) continue;
			dfs(i, select, is_done, visit, count);
		}
		cout << n - count << endl;
	}
}
