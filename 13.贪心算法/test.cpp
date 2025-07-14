/*************************************************************************
	> File Name: test.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 14 Jul 2025 11:13:24 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define MAX_N 500
char s[MAX_N + 5];
int k;

int main() {
    cin >> s >> k;
    for (int i = 0; i < k; i++) {
        int j = 0;
        while (s[j + 1] && s[j] <= s[j + 1]) ++j;
        while (s[j]) s[j] = s[j + 1], j += 1;
    }
    for (int i = 0, flag = 1; s[i]; i++) {
        if (s[i] == '0' && flag) continue; 
        cout << s[i];
        flag = 0;
    }
    cout << endl;
    return 0;
}
