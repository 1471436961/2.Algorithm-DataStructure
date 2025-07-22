/*************************************************************************
	> File Name: 1.brute_force.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 22 Jul 2025 03:12:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define TEST(func, s, t) {\
    printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t)); \
}

int brute_force(const char *s, const char *t) {
    for (int i = 0; s[i]; i++) {
        int flag = 1;
        for (int j = 0; t[j]; j++) {
            if (s[i + j] == t[j]) continue;
            flag = 0;
            break;
        }
        if (flag == 1) return i;
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t)) {
        TEST(brute_force, s, t);
    }
    return 0;
}
