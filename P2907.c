//
// Created by Kevin Ye on 10/31/2023.
// Copyright (c) KevinYe on 10/31/2023.

#include <stdio.h>

int cows(int n, int k);

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    int answer = cows(n, k);
    printf("%d\n", answer);
    return 0;
}

int cows(int n, int k) {
    if (n - k > 0 && (n - k) % 2 == 0) return cows((n - k) / 2, k) + cows((n - k) / 2 + k, k);
    else return 1;
}
