/*************************************************************************
	> File Name: 17.HZOJ-256-1.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 15 Jul 2025 09:07:31 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5], ind[MAX_N + 5];

int main() {
    int n; 
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    sort(ind + 1, ind + n + 1, [&](int i, int j) -> bool {
        return a[i] * b[i] < a[j] * b[j];
    });
    int p = a[0], ans = 0;
    for (int i = 1; i <= n; i++) {
        if (p / b[ind[i]] > ans) ans = p / b[ind[i]];
        p *= a[ind[i]];
    }
    cout << ans << endl;
    return 0;
}
