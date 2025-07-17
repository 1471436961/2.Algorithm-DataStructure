/*************************************************************************
	> File Name: 10.P1044.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 17 Jul 2025 04:37:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 18
int f[MAX_N + 5]; 

int main() {
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        for (int x = 1; x <= i; x++) {
            f[i] += f[x - 1] * f[i - x];
        }
    }
    cout << f[n] << endl;
    return 0;
}
