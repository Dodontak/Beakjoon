#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct matrix
{
	int row;
	int col;
} s_matrix;

void func(int a, int b, vector<vector<int>>& dp, const vector<s_matrix>& matrices)
{
	vector<int> vec;
	for (int i = a; i < b; i++)
	{
		int count = dp[a][i] + dp[i + 1][b] + matrices[a].row * matrices[i].col * matrices[b].col;
		vec.push_back(count);
	}
	dp[a][b] = *min_element(vec.begin(), vec.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//입력
	int N;
	cin >> N;
	vector<s_matrix> matrices(N);
	for (int i = 0; i < N; i++)
	{
		cin >> matrices[i].row >> matrices[i].col;
	}
	/*
	어떻게 짜지?
	일단 dp테이블을 만들어.
	대각선으로 이동하면서 하나씩 채워야 해.
	0,1 1,2 2,3 3,4 ... n-2,n-1 채우고
	0,2 1,3 2,4 3,5 ... n-3,n-1 채우고
	...
	0,n-1까지 채워야한다.

	1. func(a, b, dp) 하면 알아서 dp[a][b]를 채우도록 함수 하나 만들어
	2. 대각선으로 이동하면서 func를 불러와 한칸씩 채워넣어.
	3. 마지막에 dp[0][n-1] 출력해
	*/
	vector<vector<int>>dp(N, vector<int>(N, 0));

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; i + j < N; j++)
		{
			func(j, i + j, dp, matrices);
		}
	}
	cout << dp[0][N - 1] << endl;
}
/*

4
5 3
3 2
2 6
6 1
*/