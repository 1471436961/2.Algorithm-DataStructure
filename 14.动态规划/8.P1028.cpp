/*************************************************************************
	> File Name: 8.P1028.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 17 Jul 2025 03:13:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 1000

int f[MAX_N + 5] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i / 2; j++) {
            f[i] += f[j];
        }
    }
    cout << f[n] << endl;
    return 0;
}
