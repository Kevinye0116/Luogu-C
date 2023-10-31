//
// Created by Kevin Ye on 10/31/2023.
// Copyright (c) KevinYe on 10/31/2023.

#include <stdio.h>

int Blasphemy(long n, int m, const int *blood);

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        long n;
        int m;
        scanf("%ld %d", &n, &m);
        int blood[51] = {0};
        for (int j = 0; j < m; j++) scanf("%d", &blood[j]);
        int answer = Blasphemy(n, m, blood);
        printf("%d\n", answer);
    }
    return 0;
}

int Blasphemy(long n, int m, const int *blood) {
    int k = m + 1;
    int answer = 0;
}