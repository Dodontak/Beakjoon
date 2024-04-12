#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int	D(int n) {
	return (n * 2 % 10000);
}
int	S(int n) {
	if (n) {
		return (--n);
	} else {
		return (9999);
	}
}
int	L(int n) {
	return ((n % 1000) * 10 + n / 1000);
}
int	R(int n) {
	return ((n % 10) * 1000 + n / 10);
}


string	bfs(int n, int target, vector<bool>& visit)
{
	queue<pair<int, string> >	q;
	q.push(make_pair(n, ""));
	visit[n] = true;
	while (!q.empty()) {
		int	d = D(q.front().first);
		if (d == target) return (q.front().second + "D");
		int	s = S(q.front().first);
		if (s == target) return (q.front().second + "S");
		int	l = L(q.front().first);
		if (l == target) return (q.front().second + "L");
		int	r = R(q.front().first);
		if (r == target) return (q.front().second + "R");

		if (!visit[d]) {
			q.push(make_pair(d, q.front().second + "D"));
			visit[d] = true;
		}
		if (!visit[s]) {
			q.push(make_pair(s, q.front().second + "S"));
			visit[s] = true;
		}
		if (!visit[l]) {
			q.push(make_pair(l, q.front().second + "L"));
			visit[l] = true;
		}
		if (!visit[r]) {
			q.push(make_pair(r, q.front().second + "R"));
			visit[r] = true;
		}
		q.pop();
	}
	return ("");
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int	t; cin >> t;

	while (t--) {
		int	a, b;
		cin >> a >> b;
		vector<bool>	visit(10000, false);
		cout << bfs(a, b, visit) << '\n';
	}
}
