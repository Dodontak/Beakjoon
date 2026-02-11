#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void rec(int n, int count, int** answer)
{
    if (n == 1)
    {
        *answer = (int*)malloc(sizeof(int) * count);
        (*answer)[count - 1] = n;
        return;
    }
    if (n % 2 == 0)
        rec(n / 2, count + 1, answer);
    else
        rec(n * 3 + 1, count + 1, answer);
    (*answer)[count - 1] = n;
}

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.

    int* answer;
    rec(n, 1, &answer);
    return answer;
}
