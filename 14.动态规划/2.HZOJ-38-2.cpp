/*************************************************************************
	> File Name: 2.HZOJ-38-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 17 Jul 2025 09:45:29 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long f[105] = {0};

int main() {
    int n; 
    cin >> n;
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << endl;
    return 0;
}
