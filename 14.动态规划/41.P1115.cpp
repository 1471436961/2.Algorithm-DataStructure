/*************************************************************************
	> File Name: 41.P1115.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 20 Jul 2025 10:46:03 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, ans = 0x80000000, pre_dp = 0, dp; // 数据中有复数
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (pre_dp > 0) dp = pre_dp + x;
        else dp = x;
        ans = max(dp, ans);
        pre_dp = dp;
    }
    cout << ans << endl;
    return 0;
}
