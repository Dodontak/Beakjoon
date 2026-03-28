#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

// {word, count}
using PSI = pair<string, int>;

bool can_transfer(const string& str1, const string& str2)
{
    int count = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            ++count;
    }
    if (count == 1)
        return true;
    return false;
}

int bfs(const string& begin, const string& target, const vector<string>& words)
{
    queue<PSI> q;
    map<string, bool> visit;
    visit[begin] = true;
    for (int i = 0; i < words.size(); i++)
    {
        visit[words[i]] = false;
    }
    q.push({begin, 0});
    while (!q.empty())
    {
        string& cur_string = q.front().first;
        int     cur_cost = q.front().second;
        q.pop();
        if (cur_string == target)
            return cur_cost;
        for (int i = 0; i < words.size(); i++)
        {
            if (visit[words[i]] == false && can_transfer(cur_string, words[i]))
            {
                q.push({words[i], cur_cost + 1});
                visit[words[i]] = true;
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    return bfs(begin, target, words);
}