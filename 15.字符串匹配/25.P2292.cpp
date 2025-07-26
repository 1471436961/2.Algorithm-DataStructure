/*************************************************************************
	> File Name: 25.P2292.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 26 Jul 2025 07:41:36 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CNT 400
#define MAX_N 2000000
int node[MAX_CNT + 5][26];
int val[MAX_CNT + 5], dep[MAX_CNT + 5];
int cnt = 1, root = 1;
char s[MAX_N + 5];
int dp[MAX_N + 5], slen;

void insert(const char *s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (node[p][ind] == 0) {
            node[p][ind] = ++cnt;
            dep[cnt] = dep[p] + 1;
        }
        p = node[p][ind];
    }
    val[p] += 1;
    return ;
}

void mark(const char *s, int pos) {
    int p = root;
    for (int i = pos; s[i]; i++) {
        p = node[p][s[i] - 'a'];
        if (p == 0) return ;
        if (val[p]) dp[pos + dep[p]] = 1;
    }
    return ;
}

int query(const char *s) {
    for (int i = 0; i <= slen; i++) dp[i] = 0;
    int ans = 0;
    dp[0] = 1;
    for (slen = 0; s[slen]; slen++) {
        if (dp[slen] == 0) continue;
        ans = slen;
        mark(s, slen);
    }
    if (dp[slen]) ans = slen;
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(s);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return 0;
}
