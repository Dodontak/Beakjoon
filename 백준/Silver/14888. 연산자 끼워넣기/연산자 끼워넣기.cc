#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// 과제 목표
// n개의 수와 n-1개의 연산자가 주어진다.
// n개의 수는 그대로 있고 사이사이에 연산자를 끼워넣어서 모든 경우의 결과를 구하고, 최댓값과 최솟값을 구하라.
// 1. 연산자들의 모든 조합 set에 저장한다.
// 2. 연산자 세트와 숫자의 연산결과를 set에 저장한다.
// 3. front와 back을 출력한다. 끝

set<string> combs;
vector<int> numbers;
set<int> answers;

int	calculate(string comb)
{
	int	sum = numbers[0];
	for (size_t i = 0; i < comb.size(); ++i)
	{
		if (comb[i] == '+') {
			sum += numbers[i + 1];
		} else if (comb[i] == '-') {
			sum -= numbers[i + 1];
		} else if (comb[i] == '*') {
			sum *= numbers[i + 1];
		} else if (comb[i] == '/') {
			sum /= numbers[i + 1];
		}
	}
	return (sum);
}

void	recursion(string comb, vector<int> operators)
{
	if (comb.size() == numbers.size() - 1)
	{
		answers.insert(calculate(comb));
	}
	for (int i = 0; i < 4; ++i)
	{
		if (operators[i] > 0)
		{
			--operators[i];
			if (i == 0) {
				recursion(comb + "+", operators);
			} else if (i == 1) {
				recursion(comb + "-", operators);
			} else if (i == 2) {
				recursion(comb + "*", operators);
			} else if (i == 3) {
				recursion(comb + "/", operators);
			}
			++operators[i];
		}
	}
}

int	main()
{
	int	n;
	cin >> n;
	while (n--)
	{
		int	num;
		cin >> num;
		numbers.push_back(num);
	}
	vector<int>	operators(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}
	recursion("", operators);
	cout << *(--answers.end()) << '\n';
	cout << *answers.begin() << '\n';
}
