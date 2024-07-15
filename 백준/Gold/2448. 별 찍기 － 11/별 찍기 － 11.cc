#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int get_level(int n)
{
	n /= 3;
	int level = 0;
	while (n)
	{
		level++;
		n /= 2;
	}
	return (level);
}

void set_star(int center, int level, vector<string> &stars)
{
	int interval = 3 * pow(2, level);
	int width_interval = interval * 2 - 1;
	for (int i = 0; i < interval; i++)
	{
		stars[interval + i].replace(center - width_interval, width_interval, stars[i], center - interval + 1, width_interval);
		stars[interval + i].replace(center + 1, width_interval, stars[i], center - interval + 1, width_interval);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> stars(n, string(2 * n - 1, ' '));
	int center = n - 1;
	stars[0][center] = '*';
	stars[1][center + 1] = '*';
	stars[1][center - 1] = '*';
	stars[2][center - 2] = '*';
	stars[2][center - 1] = '*';
	stars[2][center] = '*';
	stars[2][center + 1] = '*';
	stars[2][center + 2] = '*';
	int max_level = get_level(n) - 1;
	for (int level = 0; level < max_level; level++)
	{
		set_star(center, level, stars);
	}

	for (int i = 0; i < stars.size(); i++)
	{
		cout << stars[i] << endl;
	}
}
