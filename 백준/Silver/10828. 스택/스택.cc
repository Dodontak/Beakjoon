#include <iostream>
#include <stack>
#include <string>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	n; cin >> n;
	string		command;
	stack<int>	st;
	int			num;
	while (n--) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			st.push(num);
		} else if (command == "pop") {
			if (st.empty()) {
				cout << -1 << endl;
			} else {
				cout << st.top() << endl;
				st.pop();
			}
		} else if (command == "size") {
			cout << st.size() << endl;
		} else if (command == "empty") {
			cout << st.empty() << endl;
		} else if (command == "top") {
			if (st.empty()) {
				cout << -1 << endl;
			} else {
				cout << st.top() << endl;
			}
		}
	}
}
