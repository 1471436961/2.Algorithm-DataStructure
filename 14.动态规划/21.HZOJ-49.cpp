/*************************************************************************
	> File Name: 21.HZOJ-49.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 18 Jul 2025 11:21:16 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_V 100000
int dp[MAX_V + 5] = {0};

int main() {
    int n, V;
    scanf("%d%d", &V, &n);
    for (int i = 1, v, w, s; i <= n; i++) {
        scanf("%d%d%d", &v, &w, &s);
        for (int k = 0; k < s; k++) {
            for (int j = V; j >= v; j--) {
                dp[j]  = max(dp[j], dp[j - v] + w);
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
