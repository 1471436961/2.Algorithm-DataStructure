/*************************************************************************
	> File Name: 6.P1605.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 13 Jul 2025 05:17:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 5
int dir[4][2] ={
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int g[MAX_N + 5][MAX_N + 5];
int n, m, t, x1, x2, y1, y2, ans;

void dfs(int x, int y) {
    if (x == x2 && y == y2) {
        ans += 1;
        return ;
    }
    g[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (g[dx][dy] == 0) continue;
        dfs(dx, dy);
    }
    g[x][y] = 1;
}

int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] = 1;
        }
    }
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for (int i = 0, x, y; i < t; i++) {
        scanf("%d%d", &x, &y);
        g[x][y] = 0;
    }
    ans = 0;
    dfs(x1, y1);
    printf("%d\n", ans);
    return 0;
}
