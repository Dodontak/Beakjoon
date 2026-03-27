#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

#define INF 50000000

using namespace std;

//pair<dist, node>
typedef pair<int, int> PII;
typedef priority_queue<PII, vector<PII>, greater<PII>> PQ;

void func(int start, const vector<set<PII>>& links, vector<int>& costs)
{
    PQ pq;
    pq.push({0, start});
    vector<bool> visit(links.size(), false);
    costs[start] = 0;
    while (!pq.empty())
    {
        int cur_node = pq.top().second;
        int cur_cost = pq.top().first;
        visit[start] = true;
        pq.pop();
        for (auto link : links[cur_node])
        {
            int link_node = link.second;
            int link_cost = link.first;
            int new_cost = cur_cost + link_cost;
            
            if (visit[link_node] == true)// 이미 방문했으면 건너뛰기
                continue;
            if (costs[link_node] > new_cost)// 기존비용보다 새 비용이 싸다면
            {
                costs[link_node] = new_cost;// 비용 갱신
                pq.push({new_cost, link_node});// 방문 예약
            }
        }
    }
}

vector<int> get_add_vec(const vector<int>& a, const vector<int>& b, const vector<int>& c)
{
    vector<int> vec;
    vec.resize(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        vec[i] = a[i] + b[i] + c[i];
    }
    return vec;
}

int get_min_vec(const vector<int>& vec)
{
    int num = INF;
    for (int i = 0; i < vec.size(); i++)
        num = min(num, vec[i]);
    return num;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<set<PII>> links(n + 1);
    
    for (int i = 0; i < fares.size(); i++)
    {
        int st = fares[i][0];
        int ed = fares[i][1];
        int cost = fares[i][2];
        
        links[st].insert({cost, ed});
        links[ed].insert({cost, st});
    }
    
    vector<int> stop_cost(n + 1, INF);
    vector<int> atop_cost(n + 1, INF);
    vector<int> btop_cost(n + 1, INF);
    func(s, links, stop_cost);
    func(a, links, atop_cost);
    func(b, links, btop_cost);
    vector<int> sum = get_add_vec(stop_cost, atop_cost, btop_cost);
    
    
    return get_min_vec(sum);
}