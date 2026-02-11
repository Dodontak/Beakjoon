#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int stk_size = 0;
    int alloc_size = 1;
    int* stk = (int*)malloc(sizeof(int) * alloc_size);
    int i = 0;
    while (1)
    {
        if (i == arr_len) break;
        if (stk_size == 0)
        {
            stk[stk_size++] = arr[i++];
        }
        else if (stk_size != 0 && stk[stk_size - 1] < arr[i])
        {
            if (stk_size == alloc_size)
            {
                alloc_size *= 2;
                stk = (int*)realloc(stk, sizeof(int) * alloc_size);
            }
            stk[stk_size++] = arr[i++];
        }
        else if (stk_size != 0 && stk[stk_size - 1] >= arr[i])
        {
            stk_size--;
        }
    }
    stk = (int*)realloc(stk, sizeof(int) * stk_size);
    return stk;
}