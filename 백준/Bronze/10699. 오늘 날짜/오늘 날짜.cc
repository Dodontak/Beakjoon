#include <iostream>
#include <ctime>

using namespace std;

int	main()
{
	time_t	timer = time(NULL);
	struct	tm* t = localtime(&timer);
	cout << t->tm_year + 1900 << '-';
	if (t->tm_mon + 1 < 10)
	{
		cout << '0';
	}
	cout << t->tm_mon + 1 << '-';
	if (t->tm_mday < 10)
	{
		cout << '0';
	}
	cout << t->tm_mday <<endl;
}
