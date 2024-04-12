#include <iostream>
#include <deque>
#include <string>

using namespace std;

//왜 파싱을 시키고 그래 ㅠㅠ

size_t	int_len(int n)
{
	size_t	len = 0;
	while (n) {
		n /= 10;
		++len;
	}
	return (len);
}

void	fill_vector(const string& array, deque<int>& dq)
{
	for (size_t i = 0, stridx = 1; i < dq.size(); ++i) {
		dq[i] = atoi(&array[stridx]);
		stridx += int_len(dq[i]) + 1;
	}
}

int	howmany_char_in_str(const string& cmd, char c)
{
	int	count = 0;
	for (size_t i = 0; i < cmd.size(); ++i) {
		if (cmd[i] == c) ++count;
	}
	return (count);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int	t; cin >> t;
	while (t--) {
		string	cmd; cin >> cmd;
		int	n; cin >> n;
		string	arr; cin >> arr;
		int	num_of_D = howmany_char_in_str(cmd, 'D');
		if (num_of_D > n) {
			cout << "error\n";
			continue;
		} else if (num_of_D == n) {
			cout << "[]\n";
			continue;
		}

		deque<int>	dq(n);
		fill_vector(arr, dq);
		bool	rotated = false;
		for (size_t i = 0; i < cmd.length(); ++i) {
			if (cmd[i] == 'R') {
				rotated = !rotated;
			} else {
				if (rotated) {
					dq.pop_back();
				} else {
					dq.pop_front();
				}
			}
		}
		cout << '[';
		if (rotated) {
			for (deque<int>::reverse_iterator it = dq.rbegin(); it != dq.rend(); ++it) {
				cout << *it;
				if (it + 1 != dq.rend()) cout << ',';
			}
		} else {
			for (deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
				cout << *it;
				if (it + 1 != dq.end()) cout << ',';
			}
		}
		cout << "]\n";
	}
}