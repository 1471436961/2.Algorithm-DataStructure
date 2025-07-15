/*************************************************************************
	> File Name: 6.HZOJ-239.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 15 Jul 2025 10:40:14 AM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#define S(a) ((a) * (a))

void f(long long n, long long s, long long &x, long long &y) {
    if (n == 1) {
        if (s == 1) x = 0, y = 0;
        else if (s == 2) x = 0, y = 1;
        else if (s == 3) x = 1, y = 1;
        else x = 1, y = 0;
        return ;
    }
    long long L = 1LL << (n - 1); // n - 1 级城市的边长
    long long block = L * L;
    long long xx, yy;
    if (s <= block) { // 1 号区域：(x, y) -> (y, x)
        f(n - 1, s, xx, yy);
        x = yy, y = xx;
    } else if (s <= 2 * block) { // 2 号区域：(x, y) -> (x, y + L)
        f(n - 1, s - block, xx, yy);
        x = xx, y = yy + L;
    } else if (s <= 3 * block) { // 3 号区域：(x, y) -> (x + L, y + L)
        f(n - 1, s - 2 * block, xx, yy);
        x = xx + L, y = yy + L;
    } else { // 4 号区域：(x, y) -> (2L - y - 1, L - x - 1)
        f(n - 1, s - 3 * block, xx, yy);
        x = 2 * L - yy - 1, y = L - xx - 1;
    }
    return ;
}

int main() {
    long long t, n, s, d;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld", &n, &s, &d);
        long long sx, sy, dx, dy;
        f(n, s, sx, sy);
        f(n, d, dx, dy);
        printf("%0.lf\n", 10 * sqrt(S(sx - dx) + S(sy - dy)));
    }
    return 0;
}
