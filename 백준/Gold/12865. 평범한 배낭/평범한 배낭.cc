#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> dp(k + 1, 0);
  vector<int> new_dp;
  vector<pair<int, int>> stuffs(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> stuffs[i].first >> stuffs[i].second;

  for (int y = 1; y <= n; y++) {
	new_dp.reserve(k + 1);
    for (int x = 0; x <= k; x++) {
      if (x - stuffs[y].first >= 0)
        new_dp[x] = max(dp[x], dp[x - stuffs[y].first] + stuffs[y].second);
      else
        new_dp[x] = dp[x];
    }
    std::swap(dp, new_dp);
  }
  cout << dp[k] << endl;
}