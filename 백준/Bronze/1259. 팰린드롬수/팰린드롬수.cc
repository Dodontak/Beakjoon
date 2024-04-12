#include <iostream>
#include <string>

using namespace std;

bool	is_pelin(const string& num)
{
	for (size_t i = 0, end = num.size() / 2; i <= end; ++i)
	{
		if (num[i] != num[num.size() - i - 1])
		{
			return (false);
		}
	}
	return (true);
}

int	main()
{
	string	num;
	while (1)
	{
		cin >> num;
		if (num == "0")
		{
			break;
		}
		if (is_pelin(num))
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}

