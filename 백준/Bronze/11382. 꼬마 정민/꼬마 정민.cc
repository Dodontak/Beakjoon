#include <iostream>

int	main()
{
	long long	num;
	long long	sum = 0;
	for (int i = 0; i < 3; i++)
	{
		std::cin >> num;
		sum += num;
	}
	std::cout << sum << std::endl;
}
