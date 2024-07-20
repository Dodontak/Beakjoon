#include <iostream>
#include <vector>

using namespace std;

int	dx[] = {1, 0, -1, 0};
int	dy[] = {0, 1, 0, -1};

bool	is_can_spread(int x, int y, const vector<vector<int> > &room) {
	if (x < 1 || x >= room[0].size() || y < 1 || y >= room.size()) return false;
	if (room[y][x] == -1) return false;
	return true;
}

vector<vector<int> >	spread_dust(const vector<vector<int> > &room) {
	vector<vector<int> >	spreaded_room(room);
	for (int y = 1; y < room.size(); ++y) {
		for (int x = 1; x < room[y].size(); ++x) {
			if (room[y][x] > 0) {
				int	spread_amount = room[y][x] / 5;
				for (int i = 0; i < 4; ++i) {
					if (is_can_spread(x + dx[i], y + dy[i], room)) {
						spreaded_room[y + dy[i]][x + dx[i]] += spread_amount;
						spreaded_room[y][x] -= spread_amount;
					}
				}
			}
		}	
	}
	return	spreaded_room;
}

void	set_next_pos(int &x, int &y, int clean_y, bool is_clockwise, const vector<vector<int> > &room) {
	if (!is_clockwise) {
		if (y == clean_y && x != room[0].size() - 1) ++x;
		else if (x == room[0].size() - 1 && y != 1) --y;
		else if (y == 1 && x != 1) --x;
		else if (x == 1 && y != clean_y) ++y;
	} else {
		if (y == clean_y && x != room[0].size() - 1) ++x;
		else if (x == room[0].size() - 1 && y != room.size() - 1) ++y;
		else if (y == room.size() - 1 && x != 1) --x;
		else if (x == 1 && y != clean_y) --y;
	}
}

void	clean_up(int clean_y, bool is_clockwise, vector<vector<int> > &room) {
	int	clean_x = 1;
	int	cur_x = clean_x + 1;
	int	cur_y = clean_y;
	int	next_x = cur_x + 1;
	int	next_y = cur_y;
	int	cur_tmp = room[cur_y][cur_x];
	int	next_tmp = room[next_y][next_x];
	room[cur_y][cur_x] = 0;
	while (1) {
		room[next_y][next_x] = cur_tmp;
		cur_x = next_x;
		cur_y = next_y;
		set_next_pos(next_x, next_y, clean_y, is_clockwise, room);
		cur_tmp = next_tmp;
		next_tmp = room[next_y][next_x];
		if (next_tmp == -1) break;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int	r, c, t;
	cin >> r >> c >> t;
	vector<vector<int> >	room(r + 1, vector<int>(c + 1));
	int	clean_y = -1;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> room[i][j];
			if (room[i][j] == -1 && clean_y == -1) clean_y = i;
		}	
	}
	for (int i = 0; i < t; i++) {
		room = spread_dust(room);
		clean_up(clean_y, false, room);
		clean_up(clean_y + 1, true, room);
	}
	int	sum = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (room[i][j] != -1) sum += room[i][j];
		}	
	}
	cout << sum << endl;
}
