/*************************************************************************
	> File Name: 18.HZOJ-47-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 18 Jul 2025 10:36:35 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_V 10000
int v[MAX_N + 5], w[MAX_N + 5];
int dp[2][MAX_V + 5] = {0}; // 优化：利用滚动数组优化空间复杂度

int main() {
    int V, n;
    scanf("%d%d", &V, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", v + i, w + i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            int ind  = i % 2, rind = (i - 1) % 2;
            dp[ind][j] = dp[rind][j];
            if (j < v[i]) continue;
            dp[ind][j] = max(dp[ind][j], dp[rind][j - v[i]] + w[i]);
        }
    }
    printf("%d\n", dp[n % 2][V]);
    return 0;
}
