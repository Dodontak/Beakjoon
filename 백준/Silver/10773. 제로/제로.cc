#include <iostream>
#include <stack>

using namespace std;

int	main()
{
	int	sum = 0;
	int	k; cin >> k;
	int	num;
	stack<int>	st;
	while (k--) {
		cin >> num;
		if (num == 0) st.pop();
		else st.push(num);
	}
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << endl;
}
