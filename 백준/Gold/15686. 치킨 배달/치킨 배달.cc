#include <iostream>
#include <vector>
#include <utility>

#define MAXDIST 2500

using namespace std;

using PII = pair<int, int>;

int get_dist(const PII &house, const PII &chicken)
{
    return (abs(house.first - chicken.first) + abs(house.second - chicken.second));
}

int get_chicken_dist(const PII &house, const vector<PII> &chickens, const vector<bool> &is_active)
{
    int dist = MAXDIST;
    for (int i = 0; i < chickens.size(); i++)
    {
        if (is_active[i] == true)
            dist = min(dist, get_dist(house, chickens[i]));
    }
    return dist;
}

int get_town_chicken_dist(const vector<PII> &houses, const vector<PII> &chickens, const vector<bool> &is_active)
{
    int sum = 0;
    for (int i = 0; i < houses.size(); i++)
    {
        sum += get_chicken_dist(houses[i], chickens, is_active);
    }
    return sum;
}

void backtracking(const vector<PII> &houses, const vector<PII> &chickens, vector<bool> &is_active, int idx,
                  int fillsize, int m, int &ans)
{
    if (fillsize == m)
    {
        ans = min(ans, get_town_chicken_dist(houses, chickens, is_active));
        return;
    }
    for (int i = idx; m - fillsize <= is_active.size() - i; i++) // 채워야할 양 <= 남은 칸수 일때만 반복
    {
        is_active[i] = true;
        backtracking(houses, chickens, is_active, i + 1, fillsize + 1, m, ans);
        is_active[i] = false;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<PII> chickens;
    vector<PII> houses;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
        {
			int item;
			cin >> item;
            if (item == 1)
                houses.push_back({j, i});
            if (item == 2)
                chickens.push_back({j, i});
        }
    }
    vector<bool> is_active(chickens.size(), false);
    int ans = MAXDIST * houses.size();
    backtracking(houses, chickens, is_active, 0, 0, m, ans);
    cout << ans << endl;
}