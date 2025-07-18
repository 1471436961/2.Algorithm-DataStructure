/*************************************************************************
	> File Name: 22.HZOJ-44.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 18 Jul 2025 11:41:09 AM CST
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using namespace std;

#define MAX_N 1000000
int val[MAX_N + 5];
int dp[MAX_N + 5] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", val + i);
    }
    val[0] = INT32_MIN;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (val[j] < val[i]) dp[i] = max(dp[i], dp[j] + 1);
        } // j = 0 表示 i 位置的数字自己独立构成一个序列
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
