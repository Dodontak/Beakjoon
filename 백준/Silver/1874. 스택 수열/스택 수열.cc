#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int	main()
{
	int	n;
	cin >> n;
	stack<int>	st;
	int			num;
	queue<int>	nums;
	queue<char>	log;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		nums.push(num);
	}
	for (int i = 1; i <= n; ++i) {
		st.push(i);
		log.push('+');
		while (st.size() > 0 && nums.size() > 0) {
			if (st.top() == nums.front()) {
				st.pop();
				nums.pop();
				log.push('-');
			} else {
				break ;
			}
		}
	}
	if (nums.size() != 0) {
		cout << "NO\n";
		return (0);
	}
	while (log.size()) {
		cout << log.front() << '\n';
		log.pop();
	}
	return (0);
}
