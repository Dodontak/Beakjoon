#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(vec);
    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
        {
            cin >> vec[y][x];
        }
    }
    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= n; ++x)
        {
            dp[y][x] = dp[y][x - 1] + dp[y - 1][x] - dp[y - 1][x - 1] + vec[y][x];
        }
    }
    while (m--)
    {
        int x1, x2, y1, y2, a, b, c, d;
        cin >> y1 >> x1 >> y2 >> x2;
        x1--;
        y1--;
        a = dp[y1][x1];
        b = dp[y1][x2];
        c = dp[y2][x1];
        d = dp[y2][x2];
        cout << (a + d - b - c) << '\n';
    }
}
