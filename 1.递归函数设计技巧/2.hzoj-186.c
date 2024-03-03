/*************************************************************************
	> File Name: hzoj.186.c
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Mar 2023 03:00:36 PM CST
 ************************************************************************/
#include <stdio.h>
#define MAX_N 100000

int jump_cnt(int arr[], int n, int cnt) {
    if (arr[n] == 0) {
        return cnt;
    }else {
        cnt++;
        return jump_cnt(arr, n + arr[n], cnt);
    }
}

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    int arr[MAX_N + 5] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", jump_cnt(arr, 0, cnt));
    return 0;
}

