/*************************************************************************
	> File Name: 16.HZOJ-279.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 26 Jul 2025 12:55:32 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 1000000
char s[MAX_N + 5], t[MAX_N + 5];

int string_min(char *s) {
    int n = strlen(s), i = 0, j = 1, k = 0;
    while (k < n && i < n && j < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) k += 1;
        else if (s[(i + k) % n] > s[(j + k) % n]) {
            i = i + k + 1;
            k = 0;
        } else {
            j = j + k + 1;
            k = 0;
        }
        if (i == j) j += 1;
    }
    return min(i, j);
}

int main() {
    int s_min, t_min;
    scanf("%s%s", s, t);
    s_min = string_min(s);
    t_min = string_min(t);
    int flag = 1;
    for (int i = s_min, j = t_min, n = 0, N = strlen(s); n < N; n++) {
        if (s[(i + n) % N] == t[(j + n) % N]) continue;
        flag = 0;
        break;
    }
    if (flag) {
        printf("Yes\n");
        for (int i = s_min, n = 0, N = strlen(s); n < N; n++) {
            printf("%c", s[(i + n) % N]);
        }
        printf("\n");
    } else {
        printf("No\n");
    }
    return 0;
}
