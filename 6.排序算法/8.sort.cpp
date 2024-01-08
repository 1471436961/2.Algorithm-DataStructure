/*************************************************************************
	> File Name: 8.sort.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 08 Jan 2024 04:43:23 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include "0.sort_test.h"
using namespace std;

void output(int *arr, int n, const char *s = "arr"); // "arr" 为默认参数
template<typename T>
void output(vector<T> &arr);

void test1() {
    printf("\ntest array : \n");
    // sort array
    int *arr = getRandData(10);
    output(arr, 10);
    sort(arr, arr + 10); // [)
    output(arr, 10);
    sort(arr, arr + 10, greater<int>()); // 从大到小
    output(arr, 10);
    free(arr);
    return ;
}

void test2() {
    printf("\ntest vector : \n");
    // sort vector
    vector<int> arr;
    for (int i = 0; i < 10; i++) arr.push_back(rand() % 10000);
    output(arr);
    sort(arr.begin(), arr.end());
    output(arr);
    sort(arr.begin(), arr.end(), greater<int>());
    output(arr);
    return ;
}

struct Data {
    int x, y;
} ;

ostream &operator<<(ostream & out, const Data &d) {
    out << "(" << d.x << ", " << d.y << ")";
    return out;
}

bool cmp(const Data &a, const Data &b) {
    if (a.x != b.x) return a.x < b.x; // a.x < b.x时a排在b前面
    return a.y > b.y; // a.x = b.x, a.y > b.y时a排在b前面
}

void test3() {
    printf("\ntest my data structure : \n");
    vector<Data> arr;
    for (int i = 0; i < 10; i++) {
        Data d;
        d.x = rand() % 10, d.y = rand() % 10;
        arr.push_back(d);
    }
    output(arr);
    sort(arr.begin(), arr.end(), cmp);
    output(arr);
    return ;
}

void test4() {
    printf("\ntest sort ind : \n");
    int *arr = getRandData(10);
    int *ind = getRandData(10);
    for (int i = 0; i < 10; i++) ind[i] = i;
    output(arr, 10);
    sort(ind, ind + 10, [&](int i, int j) -> bool {
        return arr[i] < arr[j];
    }); // lambda表达式
    output(arr, 10);
    output(ind, 10, "ind");
    return ;
} // 在不改变原数组的情况下排序

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}

template<typename T>
void output(vector<T> &arr) {
    printf("arr[%lu] = ", arr.size());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    printf("\n");
    return ;
}

void output(int *arr, int n, const char *s) {
    printf("%s[%d] = ", s, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}

