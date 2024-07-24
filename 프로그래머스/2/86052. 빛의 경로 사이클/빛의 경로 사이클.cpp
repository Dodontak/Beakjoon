#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class Agent {
public:
    Agent() {}
    Agent(int x_, int y_, int dir_) : x(x_), y(y_), dir(dir_) {}
    void    go_next(const vector<string> &grid) {
        x = x + dx[dir];
        y = y + dy[dir];
        if (x == -1) x = grid[0].size() - 1;
        else if (x == grid[0].size()) x = 0;
        else if (y == -1) y = grid.size() - 1;
        else if (y == grid.size()) y = 0;
        
        if (grid[y][x] == 'S') ;
        else if (grid[y][x] == 'R') dir = (dir + 1) % 4;
        else dir = (dir + 3) % 4;
    }
    int x;
    int y;
    int dir;
};

int fill_cycle(Agent a, vector<vector<vector<bool>>>& vec, const vector<string> &grid) {
    int time = 0;
    while (vec[a.y][a.x][a.dir] == false) {
        ++time;
        vec[a.y][a.x][a.dir] = true;
        a.go_next(grid);
    }
    return (time);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<vector<bool>>> vec(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));
    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[0].size(); x++) {
            for (int dir = 0; dir < 4; dir++) {
                int time = fill_cycle(Agent(x, y, dir), vec, grid);
                if (time != 0) answer.push_back(time);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}