#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct city
{
	int cost;
	int customers;
} s_city;

int get_vec_min(const vector<int>& vec)
{
	int min = vec[0];
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] < min)
			min = vec[i];
	return min;
}

int main()
{
	//입력
	ios::sync_with_stdio(false);
	cin.tie(0);
	// c : 늘려야하는 고객 수
	// n : 도시 수
	int c, n;
	cin >> c >> n;
	vector<s_city> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].cost >> vec[i].customers;
	}
	//DP 테이블 구하기
	vector<vector<int>> dp(c + 1, vector<int>(n, 999'999'999));
	for (int i = 0; i < n; i++)
		dp[0][i] = 0;
	vector<int> min_vec(1, 0);

	for (int customers = 1; customers <= c; ++customers)
	{
		for (int city = 0; city < n; ++city)
		{
			if (customers - vec[city].customers <= 0)
				dp[customers][city] = vec[city].cost;
			else
			{
				dp[customers][city] = min_vec[customers - vec[city].customers] + vec[city].cost;
			}
		}
		min_vec.push_back(get_vec_min(dp[customers]));
	}
	//출력
	cout << min_vec[c] << endl;
}