/*************************************************************************
	> File Name: 10.P1032.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 13 Jul 2025 08:24:00 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAX_NUM 100
int trans_cnt = 0, ans = MAX_NUM, ans_k; // ans_k 控制搜索深度
string a, b;
string from[10], to[10];
map<string, int> dp;

void dfs(string &now, int step) {
    if (step >= ans_k) return ;
    dp[now] = step;
    if (step > 10) return ;
    if (now == b) {
        ans = step;
        return ;
    }
    for (int i = 0; i < trans_cnt; i++) {
        int pos = -1;
        pos = now.find(from[i]);
        string changed; // 避免改变了 now 后回溯又要恢复
        while (pos != -1) {
            changed = now;
            changed.erase(pos, from[i].size());
            changed.insert(pos, to[i]);
            if (dp.find(changed) == dp.end() || dp[changed] > step + 1) {
                dfs(changed, step + 1);
            } // 这里应该是判断什么条件下可以继续向下搜索，而不是
            // 其对偶条件和 continue，不然后面 pos 更新的代码不会执行l; 
            pos = now.find(from[i], pos + 1); // 查找下一次匹配的位置
        }
    }
    return ;
}

int main() {
    cin >> a >> b;
    while (cin >> from[trans_cnt] >> to[trans_cnt]) trans_cnt ++;
    for (int i = 1; i <= 10; i++) {
        ans_k = i;
        dp.clear();
        dfs(a, 0);
        if (ans != MAX_NUM) break;
    } // 迭代加深
    if (ans == MAX_NUM) cout << "NO ANSWER!" << endl;
    else cout << ans << endl;
    return 0;
}
