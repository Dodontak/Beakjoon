#include <iostream>
#include <vector>

using namespace std;

int get_ans(const vector<vector<int>> &vec, int n)
{
    if (n == 1)
        return (max(vec[0][0], vec[1][0]));
    if (n == 2)
        return max(vec[0][0] + vec[1][1], vec[0][1] + vec[1][0]);
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = vec[0][0];
    dp[1][0] = vec[1][0];
    dp[0][1] = dp[1][0] + vec[0][1];
    dp[1][1] = dp[0][0] + vec[1][1];
    for (int i = 2; i < n; ++i)
    {
        dp[0][i] = vec[0][i] + max(dp[0][i - 2], max(dp[1][i - 2], dp[1][i - 1]));
        dp[1][i] = vec[1][i] + max(dp[0][i - 2], max(dp[1][i - 2], dp[0][i - 1]));
    }
    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> vec(2, vector<int>(n));
        for (int i = 0; i < n; ++i)
            cin >> vec[0][i];
        for (int i = 0; i < n; ++i)
            cin >> vec[1][i];
        cout << get_ans(vec, n) << endl;
    }
}
