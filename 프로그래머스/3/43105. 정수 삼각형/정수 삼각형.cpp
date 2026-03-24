#include <string>
#include <vector>

using namespace std;

int get_max(const vector<vector<int>>& triangle)
{
    int num = 0;
    for (int n : triangle.back())
    {
        num = max(num, n);
    }
    return num;
}

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle);
    
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if (j == triangle[i].size() - 1)
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    return get_max(dp);
}