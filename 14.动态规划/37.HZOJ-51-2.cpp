/*************************************************************************
	> File Name: 37.HZOJ-51-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 19 Jul 2025 08:27:09 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

#define MAX_N 1000
int dp[MAX_N + 5]; // 空间优化
int f[MAX_N + 5][MAX_N + 5];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (f[i][j] == 0) continue;
            f[i][j] += f[i + 1][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        stack<int> s;
        f[i][m + 1] = -1;
        s.push(m + 1);
        for (int j = m; j >= 1; j--) {
            while (f[i][s.top()] >= f[i][j]) s.pop();
            dp[j] = f[i][j] * (s.top() - j) + dp[s.top()];
            dp[j] %= 100007;
            ans += dp[j];
            ans %= 100007;
            s.push(j);
        }
    }
    printf("%d\n", ans);
    return 0;
}
