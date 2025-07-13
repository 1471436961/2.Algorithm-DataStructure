/*************************************************************************
	> File Name: 13.P2392.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 13 Jul 2025 10:09:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 20
#define MAX_NUM 9999999
int s[10] = {0}; // 存储每个科目的题目数
int t[10][MAX_N + 5]; // 存储每个科目的各个题目耗时
int ans = 0;

void dfs(int k, int x, int l, int r) {
    if (k == s[x]) {
        ans = min(ans, max(l, r));
        return ;
    }
    // 当前题目交给左脑做
    l += t[x][k];
    dfs(k + 1, x, l, r);
    l -=  t[x][k];
    // 当前题目交给右脑做
    r += t[x][k];
    dfs(k + 1, x, l, r);
    r -= t[x][k];
    return ;
} // k 表示题目序号，x 表示科目序号，l, r 表示左右脑耗时

int main() {
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> t[i][j];
        }
    }
    int total = 0;
    for (int i = 0; i < 4; i++) {
        ans = MAX_NUM;
        dfs(0, i, 0, 0);
        total += ans;
    }
    cout << total << endl;
    return 0;
}
