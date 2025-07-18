/*************************************************************************
	> File Name: 20.HZOJ-48.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 18 Jul 2025 11:09:03 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_V 10000
int dp[MAX_V + 5] = {0};

int main() {
    int n, V;
    scanf("%d%d", &n, &V);
    for (int i = 1, c, v; i <= n; i++) {
        scanf("%d%d", &c, &v);
        for (int j = c; j <= V; j++) { // 正向遍历，确保 dp[j - c] 先更新
            dp[j] = max(dp[j], dp[j - c] + v);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
