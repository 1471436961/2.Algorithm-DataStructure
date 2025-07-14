/*************************************************************************
	> File Name: 5.HZOJ-511.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 14 Jul 2025 04:30:36 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    long long a, b, k, ans;
    cin >> a >> b >> k;
    if (k == 1) {
        cout << b - a << endl;
        return 0;
    }
    if (k == 0) {
        if (b != 0) cout << b - a << endl;
        else cout << !!(a) << endl;
        return 0;
    }
    while (1) {
        if (a * k <= b) {
            ans += 1 + b % k;
            b /= k;
        } else {
            ans += (b - a);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
