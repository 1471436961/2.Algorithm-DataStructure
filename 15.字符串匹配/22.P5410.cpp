/*************************************************************************
	> File Name: 22.P5410.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 26 Jul 2025 05:25:54 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

char a[20000005], b[20000005];
long long z[20000005], p[20000005];

int main() {
    scanf("%s%s", a, b);
    long long l, r;
    l = r = -1;
    z[0] = strlen(b);
    for (int i = 1, n = z[0]; i < n; i++) {
        if (r >= i) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && b[z[i]] == b[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    l = r = -1;
    for (int i = 0, n = strlen(a); i < n; i++) {
        if (r >= i) {
            p[i] = min(z[i - l], r - i + 1);
        }
        while (i + p[i] < n && b[p[i]] == a[i + p[i]]) ++p[i];
        if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
    }
    long long ans1 = 0;
    long long ans2 = 0;
    for (int i = 0; b[i]; i++) {
        ans1 ^= (i + 1) * (z[i] + 1);
    }
    for (int i = 0; a[i]; i++) {
        ans2 ^= (i + 1) * (p[i] + 1);
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
