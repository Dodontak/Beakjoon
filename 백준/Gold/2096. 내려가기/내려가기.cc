#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, int>> vec(3, {0, 0});
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, m, r;
    pair<int, int> dpl, dpm, dpr;
    cin >> l >> m >> r;
    dpl.first = l + min(vec[0].first, vec[1].first);
    dpm.first = m + min(min(vec[0].first, vec[1].first), vec[2].first);
    dpr.first = r + min(vec[1].first, vec[2].first);

    dpl.second = l + max(vec[0].second, vec[1].second);
    dpm.second = m + max(max(vec[0].second, vec[1].second), vec[2].second);
    dpr.second = r + max(vec[1].second, vec[2].second);
    vec[0] = dpl;
    vec[1] = dpm;
    vec[2] = dpr;
  }
  cout << max(max(vec[0].second, vec[1].second), vec[2].second) << ' '
       << min(min(vec[0].first, vec[1].first), vec[2].first) << endl;
}