/*************************************************************************
	> File Name: 7.radix_sort.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 08 Jan 2024 02:56:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

void radix_sort(int *arr, int l, int r) {
    #define K 65536
    // 取基数为2的16次方，将每个32位整型分成两部分，则只需两轮排序
    int *cnt = (int *)malloc(sizeof(int) * K); // cnt数组用于统计各部分每种数字出现的次数
    int *temp = (int *)malloc(sizeof(int) * (r - l));
    // round 1
    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1]; // 求前缀和
    for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] % K]] = arr[i]; // 归位
    memcpy(arr + l, temp, sizeof(int) * (r - l));
    // round 2
    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] / K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1]; // 求前缀和
    for (int i = r - 1; i >= l; i--) temp[--cnt[arr[i] / K]] = arr[i]; // 归位
    memcpy(arr + l, temp, sizeof(int) * (r - l));  
    return ;
} // 在整型数据范围内，此排序算法的时间复杂度理论上为O(n)

int main() {
    int *arr = getRandData(BIG_DATA_N);
    TEST(radix_sort, arr, BIG_DATA_N);
    free(arr);
    return 0;
}
