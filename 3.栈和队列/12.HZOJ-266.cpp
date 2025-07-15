/*************************************************************************
	> File Name: 12.HZOJ-266.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 15 Jul 2025 12:03:37 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f

bool is_operator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return true;
        default : return false;
    }
    return false;
}

int calc(string &s, long long l, long long r) {
    long long pos = -1, pri = INF - 1, cur_pri, temp_pri = 0;
    // pri 赋初值 INF - 1，避免因和数字优先级一样造成错误更新的 bug
    for (long long i = l; i < r; i++) {
        cur_pri = INF;
        switch (s[i]) {
            case '(' : temp_pri += 100; break;
            case ')' : temp_pri -= 100; break;
            case '+' : 
            case '-' : cur_pri = 1 + temp_pri; break;
            case '*' :
            case '/' : cur_pri = 2 + temp_pri; break;
            case '^' : cur_pri = 3 + temp_pri; break;
        }
        if ((s[i] == '-' || s[i] == '+') &&
            (i - 1 < 0 || is_operator(s[i - 1]))
        ) {
            cur_pri += 1000;
        } // 解决 +n, -n 的 bug
        if (pri >= cur_pri) {
            pri = cur_pri;
            pos = i;
        } 
    } // 得到整个表达式优先级最低的运算符，即表达式树的根结点
    if (pos == -1) { // 纯数字
        long long num = 0;
        for (long long i = l; i < r; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            num  = num * 10 + (s[i] - '0');
        }
        return num;
    } else {
        long long a = calc(s, l, pos);
        long long b = calc(s, pos + 1, r);
        switch (s[pos]) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
            case '^' : return pow(a, b);
        }
    }
    return 0;
}

int main() {
    string str;
    cin >> str;
    cout << calc(str, 0, str.size()) << endl;
    return 0;
}
