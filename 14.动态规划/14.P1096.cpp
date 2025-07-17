/*************************************************************************
	> File Name: 14.P1096.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 17 Jul 2025 08:13:09 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 200

class BigInt : public vector<int> {
public:
    BigInt() { push_back(0); }
    BigInt(int x) {
        push_back(x);
        process_digit();
    }

    BigInt &operator*=(int x) {
        for (int i = 0; i < size(); i++) {
            at(i) *= x;
        }
        process_digit();
        return *this;
    }
    BigInt operator*(int x) {
        BigInt ret(*this);
        ret *= x;
        return ret;
    }
    BigInt &operator+=(int x) {
        at(0) += x;
        process_digit();
        return *this;
    }
    BigInt operator+(int x) {
        BigInt ret(*this);
        ret += x;
        return ret;
    }

    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        return ;
    }
};

BigInt f[MAX_N + 5];

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    int n;
    cin >> n;
    f[1] = 2;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] * 2 + 2; 
        // 在后面乘以 2 可以通过调用大整数的成员方法实现，
        // 在前面乘以 2 则只能在类外重载 * 运算符
    }
    cout << f[n] << endl;
    return 0;
}
