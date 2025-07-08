/*************************************************************************
	> File Name: 3.weighted_quick_union.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 08 Jul 2025 02:22:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 10000
int fa[MAX_N + 5];
int sz[MAX_N + 5]; // 用size会和标准库中的命名冲突

void init(int n) {
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    return ;
}

int find(int x) {
    if (fa[x] == x) return x;
    return find(fa[x]);
}

int merge(int a, int b) {
    int aa = find(a), bb = find(b);
    if (aa == bb) return 0;
    if (sz[aa] < sz[bb]) {
        fa[aa] = bb;
        sz[bb] += sz[aa];
    } else {
        fa[bb] = aa;
        sz[aa] += sz[bb];
    }
    return 1;
} 

void output(int n) {
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < ret; i++) printf("-");
    printf("\n");
    for (int i = 0; i <= n; i++) {
        printf("%3d", fa[i]);
    }
    printf("\n");
    for (int i = 0; i<= n; i++) {
        printf("%3d", sz[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int n, a, b;
    cin >> n;
    init(n);
    while (cin >> a >> b) {
        printf("merge %d with %d : %d\n", a, b, merge(a, b));
        output(n);
    }
    return 0;
}
