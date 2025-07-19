/*************************************************************************
	> File Name: 6.HZOJ-41-1.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 17 Jul 2025 11:29:56 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000
#define MAX_K 10

class BigInt : public vector<int> {
public:
    BigInt() { push_back(0); }
    BigInt(int x) {
        push_back(x);
        process_digit();
    }

    BigInt &operator+=(const BigInt &a) {
        for (int i = 0; i < a.size(); i++) {
            if (i < size()) at(i) += a[i];
            else push_back(a[i]);
        }
        process_digit();
        return *this;
    }

private:
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 100000) continue;
            if (i + 1 == size()) push_back(0);
            at(i + 1) += at(i) / 100000;
            at(i) %= 100000; // 大整数的一位表示实际数字的 5 位，加速计算
        } 
        return ;
    }
};

BigInt f[2][MAX_K + 5][MAX_K + 5];

ostream &operator<<(ostream &out, const BigInt &a) {
    out << a[a.size() - 1]; // 最高位可能不满 5 位
    for (int i = int(a.size()) - 2; i >= 0; i--) {
        for (int j = 10000; j > 0; j /= 10) {
            out << a[i] % (j * 10) / j;
        } // 确保输出包含前导 0 的五位数字
    }
    return out;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i ++) f[1][i][i] = 1;
    for (int ws = 2; ws <= n; ws++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                f[ws % 2][i][j] = 0; // 滚动数组，防止内存超限
                for (int l = 1; l <= k; l++) {
                    if (l == j) continue;
                    f[ws % 2][i][j] += f[(ws - 1) % 2][i][l];
                }
            }
        }
    }
    BigInt ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == j) continue;
            ans += f[n % 2][i][j];
        }
    }
    cout << ans << endl;
    return 0;
}
