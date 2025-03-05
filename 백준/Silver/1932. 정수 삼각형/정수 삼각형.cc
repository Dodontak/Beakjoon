#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> num_tri(n, vector<int>(n, 0));
    vector<vector<int>> dp(num_tri);
    // 정수 삼각형 저장
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> num_tri[i][j];
        }
    }

    // dp배열 저장
    dp[0][0] = num_tri[0][0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0) // 삼각형의 왼쪽 모서리일 경우
            {
                dp[i][j] = dp[i - 1][j] + num_tri[i][j];
            }
            else if (j == i) // 삼각형의 오른쪽 모서리일 경우
            {
                dp[i][j] = dp[i - 1][j - 1] + num_tri[i][j];
            }
            else // 그 외 중앙일 경우
            {
                dp[i][j] = max(dp[i - 1][j] + num_tri[i][j], dp[i - 1][j - 1] + num_tri[i][j]);
            }
        }
    }

    // 최댓값 구하기
    int max_num = 0;
    for (int i = 0; i < n; ++i)
    {
        max_num = max(max_num, dp[n - 1][i]);
    }
    cout << max_num << endl;
}
