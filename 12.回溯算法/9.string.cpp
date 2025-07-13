/*************************************************************************
	> File Name: 9.string.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 13 Jul 2025 08:14:51 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main() {
    string a = "abcdefgcde", b = "cde", c = "xxx";
    cout << a << " " << b << endl;
    int pos = -1;
    while (1) {
        pos = a.find(b, pos + 1); // find 的第二个参数表示查找的起始位置
        cout << pos << endl;
        if (pos == -1) break;
        a.erase(pos, b.size()); // 参数分别为删除的起始位置和长度
        a.insert(pos, c);
    }
    cout << a << endl;
    return 0;
}
