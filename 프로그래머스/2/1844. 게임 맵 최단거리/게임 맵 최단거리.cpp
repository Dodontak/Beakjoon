#include<vector>
#include<queue>

using namespace std;

class Posinfo
{
public:
    Posinfo(int xx, int yy, int ddist) : x(xx), y(yy), dist(ddist) {}
    int x;
    int y;
    int dist;
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


bool is_can_move(int x, int y, const vector<vector<bool>>& visit, const vector<vector<int> >& maps)
{
    if (x < 0 || y < 0 || x >= visit[0].size() || y >= visit.size())
        return false;
    if (maps[y][x] == 0)
        return false;
    if (visit[y][x] == true)
        return false;
    return true;
}

int bfs(const vector<vector<int> >& maps)
{
    queue<Posinfo> q;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    q.push(Posinfo(0, 0, 1));
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        if (x == maps[0].size() - 1 && y == maps.size() - 1)
            return dist;
        if (visit[y][x]) continue;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (is_can_move(xx, yy, visit, maps))
                q.push(Posinfo(xx, yy, dist + 1));
        }
        visit[y][x] = true;
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return bfs(maps);
}