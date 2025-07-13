/*************************************************************************
	> File Name: 11.P2404.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 13 Jul 2025 09:13:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int ans[20] = {0};

void print_one_result(int n) {
    if (n < 2) return ;
    for (int i = 0; i < n; i++) {
        if (i) cout << "+";
        cout << ans[i];
    }
    cout << endl;
    return ;
} 

void dfs(int k, int s_num, int n) {
    if (n == 0) {
        print_one_result(k);
    }
    if (s_num > n) return ;
    for (int i = s_num; i <= n; i++) {
        ans[k] = i;
        dfs(k + 1, i, n - i);
    }
    return ;
} // k 表示层数，s_num 表示当前拆分可以起始的数字, n 表示拆分数字的剩余量

int main() {
    int n;
    cin >> n;
    dfs(0, 1, n);

    return 0;
}
