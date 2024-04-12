#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef	unsigned int	uint;

uint	count_lines(uint len, const vector<uint>& lines)
{
	uint	count = 0;
	for (size_t i = 0; i < lines.size(); ++i)
	{
		count += lines[i] / len;
	}
	return (count);
}

uint	bin_search(uint left, uint right, const vector<uint>& lines, const uint& flag_count)
{
	if (left + 1 >= right)
	{
		if (count_lines(right, lines) >= flag_count)
		{
			return (right);
		}
		return (left);
	}
	uint	mid = (left + right) / 2;
	if (count_lines(mid, lines) >= flag_count) {
		return (bin_search(mid, right, lines, flag_count));
	} else {
		return (bin_search(left, mid - 1, lines, flag_count));
	}
}

int	main()
{
	uint	k;
	uint	n;
	uint	len;
	vector<uint>	vec;
	cin >> k >> n;
	while (k--)
	{
		cin >> len;
		vec.push_back(len);
	}
	sort(vec.begin(), vec.end());
	uint	max_len = bin_search(0, vec.back(), vec, n);
	cout << max_len << endl;
}
