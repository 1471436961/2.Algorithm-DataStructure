/*************************************************************************
	> File Name: 1.HZOJ-38.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 17 Jul 2025 09:33:46 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 100
long long arr[MAX_N + 5] = {0};

long long f(int n) {
    if (n <= 2) return n;
    if (arr[n]) return arr[n];
    arr[n] = f(n - 1) + f(n - 2);
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
