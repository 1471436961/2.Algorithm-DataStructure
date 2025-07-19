/*************************************************************************
	> File Name: 30.HZOJ-50-1.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 19 Jul 2025 11:41:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 32
#define MAX_M 100000
int dp[MAX_N + 5][MAX_M + 5];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = j;
            for (int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
