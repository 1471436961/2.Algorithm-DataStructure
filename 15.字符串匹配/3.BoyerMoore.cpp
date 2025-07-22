/*************************************************************************
	> File Name: 3.BoyerMoore.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 22 Jul 2025 04:45:10 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
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

int sunday(const char *s, const char *t) {
    // 记录黄金对齐点位在模式串中的位置，char占8位，故2 ^ 8
    int len[256] = {0}, n = strlen(s), m = strlen(t);
    for (int i = 0; i < 256; i++) len[i] = m + 1;
    for (int i = 0; t[i]; i++) len[t[i]] = m - i;
    for (int i = 0; i + m <= n; i += len[s[i + m]]) {
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

int *getDelta1(const char *t) {
    int *delta1 = (int *)malloc(sizeof(int) * 256);
    for (int i = 0; i < 256; i++) delta1[i] = -1;
    for (int i = 0; t[i]; i++) {
        delta1[t[i]] = i;
    }
    return delta1;
}

int *getSuffixes(const char *t) {
    int tlen = strlen(t);
    int *suff = (int *)malloc(sizeof(int) * tlen);
    suff[tlen - 1] = tlen;
    for (int i = 0; i < tlen - 1; i++) {
        int j = 0;
        while (j <= i && t[tlen - j - 1] == t[i - j]) ++j;
        suff[i] = j;
    }
    return suff;
} // suff 存储以 i 位置为结尾所能匹配的最大长度

int *getDelta2(const char *t) {
    int *suff = getSuffixes(t);
    int tlen = strlen(t), lastInd = tlen - 1;
    int *delta2 = (int *)malloc(sizeof(int) * tlen);
    for (int i = 0; t[i]; i++) delta2[i] = tlen;
    for (int i = 0; i < tlen; i++) {
        if (suff[i] != i + 1) continue;
        for (int j = 0; j <= lastInd - suff[i]; j++) delta2[j] = lastInd - i;
    } // 情况 2
    for (int i = 0; i < lastInd; i++) {
        delta2[lastInd - suff[i]] = lastInd - i;
    } // 情况 1
    return delta2;
}

int BM(const char *s, const char *t) {
    int *delta1 = getDelta1(t);
    int *delta2 = getDelta2(t);
    int slen = strlen(s), tlen = strlen(t);
    for (int j = 0; j + tlen <= slen;) {
        int i = tlen - 1;
        while (i >= 0 && t[i] == s[j + i]) --i;
        if (i == -1) return j;
        j += max(i - delta1[s[j + i]], delta2[i]);
    }
    return -1;
}

int main() {
    char s[100], t[100];
    while (~scanf("%s%s", s, t)) {
        TEST(brute_force, s, t);
        TEST(sunday, s, t);
        TEST(BM, s, t);
    }
    return 0;
}
