/*************************************************************************
	> File Name: 5.hzoj.595.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Aug 2023 07:25:16 PM CST
 ************************************************************************/
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, flag = 0;
    cin >> n;
    vector<string> ops(n), s;
    string target;
    for (int i = 0; i < n; i++) cin >> ops[i];
    cin >> target;
    for (int i = 0; i < n; i++) {
        if (target == ops[i]) {
            s.push_back(ops[i]);
            flag = 1;
            break;
        }
        if (ops[i] == "return") s.pop_back();
        else s.push_back(ops[i]);
    }
    if (flag) {
        for (int i = 0; i < s.size(); i++) {
            if (i) cout << "->";
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << "NOT REFERENCED" << endl;
    }
    return 0;
}

