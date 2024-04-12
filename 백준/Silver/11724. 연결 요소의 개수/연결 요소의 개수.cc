#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//큐에 1번노드 넣고 해당노드 방문하지 않았다면 bfs로 방문한곳 칠하고 count++
//2번노드 ... 3번노드 ... n번노드까지
//count 출력

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int	n; cin >> n;
	int	m; cin >> m;

	//연결됐는지 확인하기 위한 메모리
	vector<vector<int> >	vec(n, vector<int>());
	while (m--) {
		int	a, b;
		cin >> a >> b;
		vec[--a].push_back(--b);
		vec[b].push_back(a);
	}
	//방문 체크 메모리
	vector<bool>	is_visited(n, false);
	int	count = 0;

	//0~n-1노드까지 확인하면서 방문한적 없으면 count++
	//i 노드와 연결된 모든곳을 방문체크 후에 for문 한번 끝남.
	for (int i = 0; i < n; ++i) {
		if (is_visited[i]) continue;
		++count;
		queue<int>	q;
		q.push(i);
		is_visited[i] = true;
		while (!q.empty()) {
			vector<int>::iterator it = vec[q.front()].begin();
			vector<int>::iterator end = vec[q.front()].end();
			while (it != end) {
				if (!is_visited[*it]) {//방문하지 않은 곳이면
					q.push(*it);//방문 목록에 추가
					is_visited[*it] = true;//방문했다고 체크
				}
				++it;
			}
			q.pop();//방문 끝났으면 pop
		}
	}
	cout << count << '\n';
}
