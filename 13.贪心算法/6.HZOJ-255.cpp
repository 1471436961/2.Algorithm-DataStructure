/*************************************************************************
	> File Name: 6.HZOJ-255.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 14 Jul 2025 07:56:05 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_N 1000

struct Range {
    double l, r;
} arr[MAX_N + 5];

bool cmp(const Range &a, const Range &b) {
    return a.r < b.r;
}

int main() {
    int n;
    double r, x, y, pos;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (y > r) {
            cout << -1 << endl;
            return 0;
        }
        double delta = sqrt(r * r - y * y);
        arr[i].l = x - delta;
        arr[i].r = x + delta;
    }
    sort(arr, arr + n, cmp);
    int ans = 1;
    pos = arr[0].r;
    for (int i = 1; i < n; i++) {
        if (arr[i].l > pos) {
            ans += 1;
            pos = arr[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}
