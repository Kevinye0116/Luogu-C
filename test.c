//
// Created by Kevin Ye on 10/31/2023.
// Copyright (c) KevinYe on 10/31/2023.

#include<stdio.h>

int f(int x, int y);

int main(void) {
    int N;
    int K;
    scanf("%d%d", &N, &K);
    printf("%d\n", f(N, K));
    return 0;
}

int f(int x, int y) {
    int sum = 0;
    if ((x - y) % 2 == 0 && x >= y + 2) {
        sum += f((x - y) / 2, y);
        sum += f((x - y) / 2 + y, y);
        return sum;
    } else {
        sum++;
        return sum;
    }
}