/*************************************************************************
	> File Name: hzoj.184.c
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Mar 2023 02:08:22 PM CST
 ************************************************************************/
#include <stdio.h>

int peach_num(int n) {
    if (n == 1) return 1;
    return (peach_num(n - 1) + 1) * 2;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", peach_num(n));
    return 0;
}

