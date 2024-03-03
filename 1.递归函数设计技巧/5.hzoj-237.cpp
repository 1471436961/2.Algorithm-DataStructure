/*************************************************************************
	> File Name: hzoj.237.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 07 Jul 2023 08:52:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[10], vis[10] = {0};

void print_one_result(int n) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    return ;
}

void f(int i, int n) {
    if (i == n) {
        print_one_result(n);
        return ;
    }
    for (int k = 1; k <= n; k++) {
        if (vis[k]) continue;
        arr[i] = k;
        vis[k] = 1;
        f(i + 1, n);
        vis[k] = 0;
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    f(0, n);
    return 0;
}
