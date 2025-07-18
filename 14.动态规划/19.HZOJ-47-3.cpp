/*************************************************************************
	> File Name: 19.HZOJ-47-3.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 18 Jul 2025 10:41:42 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_V 10000
int dp[MAX_V + 5] = {0}; // 优化：把 dp 数组从二维变为一维，优化空间复杂度

int main() {
    int V, n;
    scanf("%d%d", &V, &n);
    for (int i = 1, v, w; i <= n; i++) {
        scanf("%d%d", &v, &w); // 优化：边读入边处理
        for (int j = V; j >= v; j--) { // 反向遍历确保dp[i - 1][j - v]未更新
            // dp[j] 更新前表示 dp[i - 1][j]，更新后表示 dp[i][j]
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
