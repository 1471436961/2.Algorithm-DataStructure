/*************************************************************************
	> File Name: 40.P1113.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 20 Jul 2025 10:35:29 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 10000 
int dp[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1, t, j; i <= n; i++) {
        cin >> t >> t;
        dp[i] = t;
        while (cin >> j) {
            if (j == 0) break;
            dp[i] = max(dp[i], dp[j] + t);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
