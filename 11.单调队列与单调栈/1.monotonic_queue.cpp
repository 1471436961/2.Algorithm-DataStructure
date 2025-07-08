/*************************************************************************
	> File Name: 1.monotonic_queue.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 08 Jul 2025 08:14:39 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
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
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    deque<int> q; // 由于单调队列入队出队的特殊性，采用双端队列模拟
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    output(arr);
    for (int i = 0; i < n; i++) {
        while (!q.empty() && arr[q.back()] > arr[i]) q.pop_back();
        q.push_back(i); 
        // 编码技巧：压入下标而不是值，因为可以通过下标访问值，
        // 但不能通过值访问下标，压入下标没有信息损失
        if (i - q.front() >= k) q.pop_front();
        printf("[%d, %d] = arr[%d] = %d\n", 
               max(i - k + 1, 0), i, 
               q.front(), arr[q.front()]
        );
    }
    return 0;
}
