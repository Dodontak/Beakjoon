#include <iostream>

using namespace std;

void	set_next_num(int& num)
{
	while (++num)
	{
		int	n = num;
		while (n)
		{
			if (n % 1000 == 666)
			{
				return ;
			}
			n /= 10;
		}
	}
}

int	main()
{
	int	n;
	cin >> n;
	int	num = 666;
	while (--n)
	{
		set_next_num(num);
	}
	cout << num << '\n';
}

