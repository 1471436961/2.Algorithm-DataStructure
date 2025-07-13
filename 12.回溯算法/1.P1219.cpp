/*************************************************************************
	> File Name: 1.P1219.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 12 Jul 2025 08:07:44 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

#define MASK(n) ((1 << (n + 1)) -2) 
// 二进制表示为最低位为0，剩下n位为1的掩码

unordered_map<int, int> ind; // 位权到编号的映射
int total_ans = 3;
int arr[20]; // 记录皇后坐标

void print_one_result(int n) {
    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    total_ans -= 1;
    return ;
}

int dfs(int i, int t1, int t2, int t3, int n) {
    if (i  > n) {
        if (total_ans) print_one_result(n);
        return 1;
    }
    int ans = 0;
    for (int t = t1; t; t -= (-t & t)) {
        int j = ind[-t & t]; // j 表示列上可以使用的最小数字
        if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n)))) {
            arr[i] = j;
            ans += dfs(i + 1, t1 ^ (1 << j), 
                t2 ^ (1 << (i + j - 1)),
                t3 ^ (1 << (i - j + n)),
                n
            ); // 更新状态码开始下一行的搜索
        } // 判断斜边是否符合要求
    }
    return ans;
} // i表示正在放置第 i 行皇后，t1, t2, t3 表示每列、正斜边、反斜边的状态码

int main() {
    int n, MASK;
    scanf("%d", &n);
    total_ans = 3;
    for (int i = 0; i < 2 * n; i ++) ind[1 << i] = i;
    int ans = dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1), n);
    printf("%d\n", ans);
    return 0;
}
