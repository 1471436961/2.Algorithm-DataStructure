/*************************************************************************
	> File Name: 19.HZOJ-283.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 26 Jul 2025 02:43:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100000
char s[MAX_N + 5];
int node[MAX_N + 5][10];
int val[MAX_N + 5], child[MAX_N + 5];
int cnt = 1, root = 1;

int insert(const char *s) {
    int p = 1, sum = 0;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - '0';
        if (node[p][ind] == 0) {
            node[p][ind] = ++cnt;
            child[p] += 1;
        }
        p = node[p][ind];
        sum += val[p]; // 用于判断别人是否是我的前缀
    }
    val[p] += 1;
    return !(sum == 0 && child[p] ==0); // 用于判断我是否是别人的前缀 
}

int main() {
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        flag += insert(s);
    }
    printf("%s\n", flag ? "NO" : "YES");
    return 0;
}
