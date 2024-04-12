#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//(x_st, y_st) , (x_ed, y_ed) 정보 저장하는 클래스
class	IdxInfo {
public:
	IdxInfo(int xst, int yst, int xed, int yed) : x_st(xst), y_st(yst), x_ed(xed), y_ed(yed) {}
	const int	x_st;
	const int	y_st;
	const int	x_ed;
	const int	y_ed;
};

//종이에서 (x_st, y_st) , (x_ed, y_ed)범위가 한가지 색으로 됐는지 확인하는 함수
bool	is_good(const vector<vector<bool> >& vec, const IdxInfo& idx_info)
{
	bool	color = vec[idx_info.y_st][idx_info.x_st];
	for (int y = idx_info.y_st; y <= idx_info.y_ed; ++y) {
		for (int x = idx_info.x_st; x <= idx_info.x_ed; ++x) {
			if (vec[y][x] != color) {
				return (false);
			}
		}
	}
	return (true);
}

//queue에 전체 종이 넣고 is_good이 false이면 IdxInfo를 4등분해서 다시queue에 넣고 pop
//good이면 해당 종이 색 count++ 하고 pop
int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<IdxInfo>	q;
	int	n; cin >> n;
	vector<vector<bool> >	vec(n, vector<bool>(n));
	bool	color;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> color;
			vec[i][j] = color;
		}
	}
	q.push(IdxInfo(0, 0, n - 1, n - 1));
	vector<int>	count(2, 0);
	while (!q.empty()) {
		IdxInfo	tmp = q.front();
		if (is_good(vec, tmp)) {
			++count[vec[tmp.y_st][tmp.x_st]];
			q.pop();
		} else {
			int	x_mid = (tmp.x_st + tmp.x_ed) / 2;
			int	y_mid = (tmp.y_st + tmp.y_ed) / 2;
			q.push(IdxInfo(tmp.x_st, tmp.y_st, x_mid, y_mid));
			q.push(IdxInfo(x_mid + 1, tmp.y_st, tmp.x_ed, y_mid));
			q.push(IdxInfo(tmp.x_st, y_mid + 1, x_mid, tmp.y_ed));
			q.push(IdxInfo(x_mid + 1, y_mid + 1, tmp.x_ed, tmp.y_ed));
			q.pop();
		}
	}
	cout << count[0] << endl;
	cout << count[1] << endl;
}
