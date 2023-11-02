//
// Created by Kevin Ye on 10/31/2023.
// Copyright (c) KevinYe on 10/31/2023.

#include <stdio.h>

#define MAX_SIZE 1000

int heap[MAX_SIZE];
int heapSize = 0;

void swap(int *a, int *b);

int Parent(int i);

int LeftChild(int i);

int RightChild(int i);

void MinHeapify(int index);

void Insert(int x);

void DeleteMin();

int main(void) {
    int n;
    scanf("%d", &n);
    int answer[MAX_SIZE] = {0};
    int index = 0;
    for (int i = 1; i <= n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x;
            scanf("%d", &x);
            Insert(x);
        } else if (op == 2) {
            answer[index++] = heap[0];
        } else {
            DeleteMin();
        }
    }
    for (int i = 0; i < index; i++) printf("%d\n", answer[i]);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Parent(int i) {
    return (i - 1) / 2;
}

int LeftChild(int i) {
    return 2 * i + 1;
}

int RightChild(int i) {
    return 2 * i + 2;
}

void MinHeapify(int index) {
    int min_index = index;
    int left = LeftChild(index);
    int right = RightChild(index);

    if (left < heapSize && heap[left] < heap[min_index]) min_index = left;
    if (right < heapSize && heap[right] < heap[min_index]) min_index = right;

    if (index != min_index) {
        swap(&heap[index], &heap[min_index]);
        MinHeapify(min_index);
    }
}

void Insert(int x) {
    heap[heapSize] = x;

    int current = heapSize;
    while (current > 0 && heap[current] < heap[Parent(current)]) {
        swap(&heap[current], &heap[Parent(current)]);
        current = Parent(current);
    }

    heapSize++;
}

void DeleteMin() {
    heap[0] = heap[heapSize - 1];
    heapSize--;
    MinHeapify(0);
}