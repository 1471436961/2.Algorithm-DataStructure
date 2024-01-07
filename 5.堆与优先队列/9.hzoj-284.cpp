/*************************************************************************
	> File Name: 9.hzoj-284.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 07 Jan 2024 11:14:56 AM CST
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Data {
    Data(int p, int d) : p(p), d(d) {} // 构造函数，给p, d赋值
    int p, d;
    bool operator<(const Data &obj) const {
        if (d != obj.d) return d < obj.d; // 过期日期不一样时按过期日期d从小到大排序
        return p > obj.p; // 过期日期一样时按利润p从大到小排序
    } // 重载
} ;

typedef pair<int, int> PII; // 第一个int代表利润，第二个代表序号 

int main() {
    int n; 
    cin >> n;
    vector<Data> arr;
    set<PII> s;
    for (int i = 0, p, d; i < n; i++) {
        cin >> p >> d;
        arr.push_back(Data(p, d));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(PII(arr[i].p, i));
        } else {
            if (arr[i].p > s.begin()->first) {
                s.erase(s.begin());
                s.insert(PII(arr[i].p, i));
            }
        }
    }
    int ans = 0;
    for (auto x : s) {
        ans += x.first;
    }
    cout << ans << endl;
    return 0;
}
