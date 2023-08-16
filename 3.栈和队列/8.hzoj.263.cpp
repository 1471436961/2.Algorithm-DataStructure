/*************************************************************************
	> File Name: 8.hzoj.263.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Aug 2023 03:25:48 PM CST
 ************************************************************************/

#include<iostream>
#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

bool isValid(int a[], int n) {
    stack<int> s;
    int x = 1;
    for (int i = 0; i < n; i++) {
        if (s.empty() || s.top() < a[i]) {
            while (x <= a[i]) s.push(x), x += 1;
        }
        if (s.empty() || s.top() != a[i]) return false;
        s.pop();
    }
    return true;
}

int main () {
    int n, a[25], cnt = 20;
    cin >> n;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        if (isValid(a, n)) {
            for (int i = 0; i < n; i++) {
                cout << a[i];
            }
            cout << endl;
            cnt -= 1;
        }
    } while (next_permutation(a, a + n) && cnt);
    return 0;
}
