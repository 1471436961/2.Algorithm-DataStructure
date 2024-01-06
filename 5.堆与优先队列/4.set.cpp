/*************************************************************************
	> File Name: 4.set.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 06 Jan 2024 05:03:18 PM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <time.h>
using namespace std;

void test1() {
    cout << "set base usage" << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3); // 3 
    cout << s.size() << endl;
    s.insert(4); // 3, 4
    cout << s.size() << endl;
    s.insert(2); // 3, 4, 2
    cout << s.size() << endl;
    return ;
}

void test2() {
    cout << "set item unique feature: " << endl;
    set<int> s;
    cout << s.size() << endl;
    s.insert(3);
    cout << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
    s.insert(4);
    cout << "insert 4 : " << s.size() << endl;
}

void test3() {
    cout << "set item unique feature 2: " << endl;
    typedef pair<int, int> PII; 
    // 将两个int类型打包为一个数据类型，可以规定第一个int为原数值，第二个int为存入的顺序
    set<PII> s;
    int tot = 0;
    cout << s.size() << endl;
    s.insert(PII(3, tot++));
    cout << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4 : " << s.size() << endl;
    s.insert(PII(4, tot++));
    cout << "insert 4 : " << s.size() << endl;
}

void test4() {
    cout << "foreach set item : " << endl;
    typedef pair<int, int> PII; 
    set<PII> s;
    int tot = 0;
    s.insert(PII(4, tot++));
    s.insert(PII(3, tot++));
    s.insert(PII(4, tot++));
    for (auto x : s) { // x依次遍历s集合中的所有元素
         cout << "(" << x.first << ", " << x.second << ")" << endl; 
    } // 集合遍历的顺序是按集合中所存储值的大小遍历
    return ;
}

void test5() {
    cout << "set replace heap : " << endl;
    typedef pair<int, int> PII;
    int tot = 0;
    set<PII> s;
    for (int i = 0; i < 10; i++) {
        s.insert(PII(rand() % 20, tot++)); // push
    }
    for (int i = 0; i < 4; i++) {
        cout << "s.begin() = " << s.begin()->first << endl; 
        // s.begin是指向第一个元素的迭代器，通过s.begin访问集合中的第一个元素，即最小值；top
        s.erase(s.begin()); // pop
        cout << "pop heap" << endl;
    } // set天生就是小顶堆，而要用set模拟大顶堆，可以将集合中的元素全部取相反数后再存入集合中,取出元素时再取反即可(其他方法涉及C++)
    return ;
}

int main() {
    srand(time(0));
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

