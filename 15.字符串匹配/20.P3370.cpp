/*************************************************************************
	> File Name: 20.P3370.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 26 Jul 2025 04:36:32 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int get_hash(string &s) {
    int base = 131, h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * base + s[i];
    }
    return h;
}

int main() {
    int n, hash_code, ans = 0;
    unordered_map<int, vector<string>> h;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        hash_code = get_hash(s);
        if (h.find(hash_code) == h.end()) {
            ans += 1;
            h[hash_code].push_back(s);
        } else {
            int flag = 1;
            for (auto t : h[hash_code]) {
                if (t != s) continue;
                flag = 0;
                break;
            }
            if (flag) {
                ans += 1;
                h[hash_code].push_back(s);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
