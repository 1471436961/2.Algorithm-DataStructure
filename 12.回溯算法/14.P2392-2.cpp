/*************************************************************************
	> File Name: 14.P2392-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 13 Jul 2025 10:37:27 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;


#define MAX_N 20
#define MAX_NUM 9999999
int s[10], sum[10] = {0}; // sum 存储每个科目题目的总耗时
int t[10][MAX_N + 5];
unordered_map<int, int> ind; // ind 存储题目序号到该题耗时索引的映射 

int solve(int k) {
    int ans = MAX_NUM;
    int T = (1 << s[k]);
    for (int i = 0; i < T; i++) {
        int j = i, l = 0, r = 0;
        while (j) {
            l += t[k][ind[j & -j]];
            j -= (j & -j);
        }
        r = sum[k] - l;
        ans = min(ans, max(l, r));
    } // j 的二进制表示中，1表示对应题目给左脑做，0表示对应题目给右脑做
    return ans;
} // 利用二进制表示和二项分布的关系枚举

int main() {
    for (int i = 0; i < 4; i++) cin >> s[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s[i]; j++) {
            cin >> t[i][j];
            sum[i] += t[i][j];
        }
    }
    for (int k = 1, i = 0; i <= MAX_N; i++, k *= 2) ind[k] = i; // 状态压缩
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += solve(i);
    }
    cout << ans << endl;
    return 0;
}
