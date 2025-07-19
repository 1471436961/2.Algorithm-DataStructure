/*************************************************************************
	> File Name: 32.HZOJ-46-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 19 Jul 2025 03:22:12 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_N 500000
int dp[MAX_N + 5];
char s[MAX_N + 5];
vector<int> g[MAX_N + 5]; // g[i] 中存储所有能和 i 位置构成回文串的下标 j

void extract(int i, int j) {
    while (s[i] == s[j]) {
        g[i].push_back(j - 1);
        i++, j--;
    }
    return ;
}

int main() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        extract(i, i);
        extract(i, i + 1);
    }
    dp[0] = -1; 
    // 特殊处理，将判断整个字符串是否是回文串的逻辑
    // 合并到判断最后一刀之后的字符串是否是回文串
    for (int i = 1; s[i]; i++) {
        dp[i] = i;
        for (auto j : g[i]) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
