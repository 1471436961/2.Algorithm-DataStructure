/*************************************************************************
	> File Name: 2.monotonic_stack.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 08 Jul 2025 09:04:01 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void output(vector<int> &arr) {
    int n = arr.size(), len = 0;
    for (int i = 0; i < n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
    return ;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    arr.push_back(-1);
    stack<int> s; 
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    arr.push_back(-1); // 在数组的第一位和最后一位加上极小值
    vector<int> l(arr.size() + 1), r(arr.size() + 1); 
    // l, r分别记录当前元素左右两边离它最近的小于它的元素
    output(arr);
    // right
    for (int i = 0, I = arr.size(); i < I; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    // left
    while (!s.empty()) s.pop();
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    // output result
    for (int i = 1; i <= n; i ++) {
        printf("arr[%d] = %d, right : arr[%d] = %d, left : arr[%d] = %d\n",
               i, arr[i],
               r[i], arr[r[i]],
               l[i], arr[l[i]]
              );
    }
    return 0;
}

