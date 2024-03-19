/*************************************************************************
	> File Name: 2.insert_sort.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 07 Jan 2024 06:31:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "0.sort_test.h"

void insert_sort(int *arr, int l, int r) {
    for (int i = l + 1; i < r; i ++) {
        int j = i;
        while (j > l && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]); 
            j -= 1;
        }
    }
    return ;
}

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    } // 增加了O(n)
    while(ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    } // 平移而不直接交换保证插入排序的稳定性
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]) ; // 初始逆序数为O(n2)，每执行一次逆序数减1
            j -= 1;
        }
    } // j > l的判断次数相当于交换次数，故减少了O(n2)
    return ;
}

int main() {
    int *arr = getRandData(SMALL_DATA_N);
    TEST(insert_sort, arr, SMALL_DATA_N);
    TEST(unguarded_insert_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}
