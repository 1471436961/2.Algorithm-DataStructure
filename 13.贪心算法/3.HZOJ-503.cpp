/*************************************************************************
	> File Name: 3.HZOJ-503.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 14 Jul 2025 03:23:10 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1, cnt = 0;
    while (i < j) {
        if (arr[i] + arr[j] <= w) {
            i++, j--;
        } else {
            j--;
        }
        cnt += 1;
    }
    if (i == j) cnt += 1;
    cout << cnt << endl;
    return 0;
}
