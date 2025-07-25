/*************************************************************************
	> File Name: 34.HZOJ-49-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 19 Jul 2025 07:16:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_V 100000
int dp[MAX_V + 5] = {0};

int main() {
    int V, n;
    scanf("%d%d", &V, &n);
    for (int i = 0, v, w, s; i < n; i++) {
        scanf("%d%d%d", &v, &w, &s);
        for (int k = 1; s; s -= k, k *= 2) {
            k = min(s, k);
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j], dp[j - k *v] + k * w);
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
