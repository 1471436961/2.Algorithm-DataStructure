/*************************************************************************
	> File Name: 48.P1681.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 20 Jul 2025 03:45:30 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 1500
int dp[MAX_N + 5][MAX_N + 5][2];

int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, a; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a);
            dp[i][j][1 - a] = 0;
            dp[i][j][a] = min(
                dp[i - 1][j - 1][a], min(
                dp[i - 1][j][1 - a], 
                dp[i][j - 1][1 - a]
            )) + 1;
            ans = max(ans, dp[i][j][a]);
        }
    }
    cout << ans << endl;
    return 0;
}
