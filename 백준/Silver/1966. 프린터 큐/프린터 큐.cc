#include <iostream>
#include <queue>
#include <utility>

using namespace	std;

int	main()
{
	int	test_case; cin >> test_case;
	for (int i = 0; i < test_case; ++i)
	{
		queue<pair<int ,int> >	q;
		priority_queue<int>		pq;
		int	n; cin >> n;
		int	target_idx; cin >> target_idx;
		int	count = 0;
		for (int i = 0; i < n; ++i)
		{
			int	priority; cin >> priority;
			q.push(make_pair(i, priority));
			pq.push(priority);
		}
		while (!q.empty())
		{
			if (q.front().second == pq.top())
			{
				++count;
				if (q.front().first == target_idx)
				{
					cout << count << endl;
					break ;
				}
				q.pop();
				pq.pop();
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
	}
}
