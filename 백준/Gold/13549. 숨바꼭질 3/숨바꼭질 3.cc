#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// pair<time, pos>
using PII = pair<int, int>;
using PQ = priority_queue<PII, vector<PII>, greater<PII>>;

bool can_visit_pos(int pos, const vector<bool> &visit)
{
    if (pos < 0 || pos >= visit.size())
        return false;
    if (visit[pos] == true)
        return false;
    return true;
}

int func(int start, int dest)
{
    if (start >= dest)
        return start - dest;
    PQ pq;
    vector<bool> visit(dest * 3, false);
    pq.push({0, start});
    visit[start] = true;
    while (!pq.empty())
    {
        int cur_pos = pq.top().second;
        int cur_time = pq.top().first;
        pq.pop();
        visit[cur_pos] = true;
        if (cur_pos == dest)
            return cur_time;
        if (can_visit_pos(cur_pos + 1, visit))
        {
            pq.push({cur_time + 1, cur_pos + 1});
        }
        if (can_visit_pos(cur_pos - 1, visit))
        {
            pq.push({cur_time + 1, cur_pos - 1});
        }
        if (can_visit_pos(cur_pos * 2, visit))
        {
            pq.push({cur_time, cur_pos * 2});
        }
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << func(n, k) << endl;
}