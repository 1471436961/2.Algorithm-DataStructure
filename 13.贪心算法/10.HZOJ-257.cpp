/*************************************************************************
	> File Name: 10.HZOJ-257.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 14 Jul 2025 10:16:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 1000

int C[MAX_N + 5] = {0};
int fa[MAX_N + 5] = {0};
int vis[MAX_N + 5] = {0};
int cnt[MAX_N + 5] = {0}; // 存储结点包含的原始结点数量
double w[MAX_N + 5] = {0}; // 存储结点用于比较的权值
int n, r;
long long ans = 0;

int find_x() {
    int x = -1;
    for (int i = 1; i <= n; i++) {
        if (i == r || vis[i] == 1) continue;
        if (x == -1 || w[x] < w[i]) x = i;
    }
    return x;
}

int find_father(int x) {
    if (vis[fa[x]]) return find_father(fa[x]);
    return fa[x];
}

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        ans += C[i];
        fa[i] = i;
        w[i] = C[i];
        cnt[i] = 1;
    }
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        fa[b] = a;
    }
    for (int i = 1; i < n; i++) {
        int x = find_x();
        int father_x = find_father(x);
        ans += cnt[father_x] * C[x];
        C[father_x] += C[x];
        cnt[father_x] += cnt[x];
        w[father_x] = 1.0 * C[father_x] / cnt[father_x];
        vis[x] = 1;
    }
    cout << ans << endl;
    return 0;
}
