/*************************************************************************
	> File Name: 33.HZOJ-44-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 19 Jul 2025 06:54:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 1000000
int dp[MAX_N + 5], len[MAX_N + 5];

int binary_search(int *len, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (len[mid] < x) head = mid;
        else tail = mid -1;
    }
    return head;
} // 11110000 找最后一个 1

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    len[0] = -1;
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        dp[i] = binary_search(len, ans, a) + 1;
        len[dp[i]] = a;
        if (dp[i] > ans) ans = dp[i];
    }
    printf("%d\n", ans);
    return 0;
}
