/*************************************************************************
	> File Name: hzoj.186.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Mar 2023 03:00:36 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int f(int i, vector<int> &arr, int n) {
    if (i >= n) return 0;
    return f(i + arr[i], arr, n) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    cout << f(0, arr, n) << endl;
    return 0;
}

