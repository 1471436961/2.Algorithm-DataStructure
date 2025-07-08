/*************************************************************************
	> File Name: 4.HZOJ-270.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 08 Jul 2025 09:40:29 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1);
    deque<int> q;
    s.push_back(0); 
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1]; // 利用前缀和
    }
    q.push_back(0); // 利用单调队列维护区间最小值
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, s[i] - s[q.front()]);
        while (!q.empty() && s[i] < s[q.back()]) q.pop_back();
        q.push_back(i);
        if (q.front() == i - m) q.pop_front();
    }
    cout << ans << endl;
    return 0;
}
