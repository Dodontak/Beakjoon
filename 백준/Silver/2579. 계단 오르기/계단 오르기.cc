#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
/*
확인해볼 것 하나. 밟는 횟수를 늘리는건 항상 최선의 전략일까? X 1 20 1 20 1 20 1 20 이렇게 있으면 밟는 갯수 최소로 하면서 가도 최선의 선택임.
둘. 밟을 수 있는 것중에서 가장 큰 수를 밟는건 항상 최선의 전략일까? X -> 타일 상황에 따라 달라짐.
셋. dp로 풀 수 있는가? (n번째 계단에 도달했을 때 최대치를 기록하는 방식이 가능할까?) 어렵다. 어떻게 잘하면 될거같긴 한데...
dfs bfs 로 풀어야할 문제일까? 될듯. 해보자. 오늘은 dfs먼저. -> 넘 오래걸림 + 왜인지틀림 + 메모리문제
*/

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int	n; cin >> n;
	vector<int>	vec(n + 1, 0);
	vector<int>	dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> vec[i];
	}
	dp[0] = 0;
	dp[1] = vec[1];
	dp[2] = dp[1] + vec[2];
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]);
	}
	cout << dp[n] << endl;
}
