#include <iostream>

int	main()
{
	int	N, M;
	int	a,b;
	int	tmp;

	std::cin >> N;
	std::cin >> M;
	int	*arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < M; i++)
	{
		std::cin >> a >> b;
		tmp = arr[a - 1];
		arr[a - 1] = arr[b - 1];
		arr[b - 1] = tmp;
	}
	for (int i = 0; i < N; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	delete[] arr;
}
