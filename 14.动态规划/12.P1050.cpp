/*************************************************************************
	> File Name: 12.P1050.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 17 Jul 2025 06:35:25 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigInt : public vector<int> {
public:
    BigInt() { push_back(0);}
    BigInt(int n, int v) : vector<int>(n, v) {}
    BigInt(int x) {
        push_back(x);
        process_digit();
    }
    BigInt(string &s, int k) {
        for (int i = 0, j = s.size() - 1; i < k; i++, j--) {
            push_back(s[j] - '0');
        }
        return ;
    }
    BigInt &operator*=(int x) {
        for (int i = 0; i < size(); i++) at(i) *= x;
        process_digit();
        return *this;
    }
    BigInt operator*(const BigInt &a) {
        BigInt ret(min(MaxLen, int(size() + a.size() - 1)), 0);
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                if (i + j >= MaxLen) continue;
                ret[i + j] += at(i) * a[j];
            }
        }
        ret.process_digit();
        return ret;
    }

    static int MaxLen;

private:
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 < MaxLen) {
                if (i + 1 == size()) push_back(0);
                at(i + 1) += at(i) / 10;
            }
            at(i) %= 10;
        }
        return ;
    }
};

int BigInt::MaxLen = 0;

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    BigInt::MaxLen = k;
    BigInt n(s, k);
    BigInt pre_y = n, y;
    vector<int> arr;
    for (int i = 0; i < n.size(); i++) {
        y = pre_y;
        int cnt = 1;
        while ((y * n).at(i) != n[i]) {
            y = y * pre_y;
            cnt += 1;
            if (cnt == 11) break; // 由鸽笼原理得当前位不循环
        }
        if (cnt == 11) {
            cout << "-1" << endl;
            return 0;
        }
        arr.push_back(cnt);
        pre_y = y;
    } // 按位确定 n 的循环节长度
    BigInt ans = 1;
    for (int i = 0; i < arr.size(); i++) {
        ans *= arr[i];
    }
    cout << ans << endl;
    return 0;
}
