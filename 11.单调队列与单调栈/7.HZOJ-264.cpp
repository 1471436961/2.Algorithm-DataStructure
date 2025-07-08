/*************************************************************************
	> File Name: 7.HZOJ-264.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 08 Jul 2025 10:37:21 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    // 分别以每一个矩形的高为面积最大的矩形的高
    // 利用单调栈求每一个矩形左右两边最近的高度小于它的矩形
    long long n;
    scanf("%lld", &n);
    vector<long long> arr(n + 2, -1), l(n + 2), r(n + 2);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }
    stack<long long> s;
    for (long long i = 1; i <= n; i++) {
        while(!s.empty() && arr[i] < arr[s.top()]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (long long i = n; i >= 1; i--) {
         while(!s.empty() && arr[i] < arr[s.top()]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);      
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        long long height = arr[i], width = r[i] - l[i] - 1;
        ans = max(ans, height * width);
    }
    printf("%lld\n", ans);
    return 0;
}
