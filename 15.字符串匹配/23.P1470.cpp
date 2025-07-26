/*************************************************************************
	> File Name: 23.P1470.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 26 Jul 2025 06:53:07 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#define MAX_N 200000
int node[MAX_N + 5][26];
int val[MAX_N + 5], dep[MAX_N + 5];
int cnt = 1, root = 1;
int dp[MAX_N + 5] = {0};

void insert(string &s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'A';
        if (node[p][ind] == 0) {
            node[p][ind] = ++cnt;
            dep[cnt] = dep[p] + 1;
        }
        p = node[p][ind];
    }
    val[p] += 1;
    return ;
}

void mark(string &s, int pos) {
    int p = root;
    for (int i = pos; s[i]; i++) {
        int ind = s[i] - 'A';
        p = node[p][ind];
        if (p == 0) break;
        if (val[p]) dp[pos + dep[p]] = 1;
    }
    return ;
}

int main() {
    string s = "", t;
    while (cin >> s) {
        if (s == ".") break;
        insert(s);
    }
    s = "";
    while (cin >> t) s += t;
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        if (dp[i] == 0) continue;
        ans = i;
        mark(s, i);
    }
    if (dp[s.size()]) ans = s.size();
    cout << ans << endl;
    return 0;
}
