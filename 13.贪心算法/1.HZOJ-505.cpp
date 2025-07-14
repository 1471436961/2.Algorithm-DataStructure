/*************************************************************************
	> File Name: 1.HZOJ-505.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 14 Jul 2025 09:40:42 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    vector<string> arr;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
