/*************************************************************************
	> File Name: 5.quick_sort.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 07 Jan 2024 09:54:07 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "0.sort_test.h"

void quick_sort(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    // partition
    int x = l, y = r - 1, z = arr[l];
    while (x < y) {
        while (x < y && z <= arr[y]) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
    return ;
}

void quick_sort_v1(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    // partition
    int x = l, y = r - 1, z = arr[l];
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    quick_sort_v1(arr, l, x);
    quick_sort_v1(arr, x, r);
    return ;
} // 优化1：减少比较次数

int three_point_select(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b; 
}

void quick_sort_v2(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    // partition
    int x = l, y = r - 1;
    int z = three_point_select(
        arr[l], 
        arr[r - 1], 
        arr[(l + r) / 2]
    );
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    quick_sort_v2(arr, l, x);
    quick_sort_v2(arr, x, r);
    return ;
} // 优化2：三点取中法

void quick_sort_v3(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l <= 1) return ;
        if (arr[l] > arr[l + 1]) swap(arr[l], arr[l + 1]);
        return ;
    }
    while (l < r) {
        // partition
        int x = l, y = r - 1;
        int z = three_point_select(
            arr[l], 
            arr[r - 1], 
           arr[(l + r) / 2]
        );
        do {
           while (arr[x] < z) ++x;
           while (arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_v3(arr, l, x); // left
        l = x; // 在本层函数处理右半部分
    }
    return ;
} // 优化3：单边递归法

#define threshold 16

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    while(ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    } // 平移而不直接交换保证插入排序的稳定性
    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]) ; // 每执行一次逆序数减1
            j -= 1;
        }
    }
    return ;
}

void __quick_sort_v4(int *arr, int l, int r) {
    while (r - l > threshold) {
        // partition
        int x = l, y = r - 1;
        int z = three_point_select(
            arr[l], 
            arr[r - 1], 
           arr[(l + r) / 2]
        );
        do {
           while (arr[x] < z) ++x;
           while (arr[y] > z) --y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        __quick_sort_v4(arr, l, x); // left
        l = x; // 在本层函数处理右半部分
    }
    return ;
} // 优化4：先快排再插入排序

void quick_sort_v4(int *arr, int l, int r) {
    __quick_sort_v4(arr, l, r);
    unguarded_insert_sort(arr, l, r);
    return ;
}

int main() {
    int *arr = getRandData(BIG_DATA_N);
    TEST(quick_sort, arr, BIG_DATA_N);
    TEST(quick_sort_v1, arr, BIG_DATA_N);
    TEST(quick_sort_v2, arr, BIG_DATA_N);
    TEST(quick_sort_v3, arr, BIG_DATA_N);
    TEST(quick_sort_v4, arr, BIG_DATA_N);
    free(arr);
    return 0;
}
