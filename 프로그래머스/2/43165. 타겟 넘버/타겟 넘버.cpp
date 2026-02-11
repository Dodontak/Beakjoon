#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, int sum, int idx, const int& target, int& answer)
{
    if (idx == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }
    dfs(numbers, sum + numbers[idx], idx + 1, target, answer);
    dfs(numbers, sum - numbers[idx], idx + 1, target, answer);
}

int solution(vector<int> numbers, int target) {
    
    int answer = 0;
    dfs(numbers, 0, 0, target, answer);
    return answer;
}