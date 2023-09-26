/*************************************************************************
	> File Name: 5.random_data.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 26 Sep 2023 09:37:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    printf("26\n");
    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", 'a' + i, rand() % 100000);
    }
    return 0;
}

