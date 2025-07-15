/*************************************************************************
	> File Name: 16.HZOJ-251.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 15 Jul 2025 08:40:47 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int X, Y, costX = 0, costY = 0;
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) x[i] = x[i] - i;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    X = x[n / 2];
    Y = y[n / 2];
    for (int i = 0; i < n; i++) costX += abs(x[i] - X);
    for (int i = 0; i < n; i++) costY += abs(y[i] - Y);
    cout << costX + costY << endl;
    return 0;
}
