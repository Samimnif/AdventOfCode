//
// Created by sami mnif on 2025-10-07.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node {
    unsigned long long data;
    struct node* next;
};

int getNumDigits(unsigned long long n) {   // << make it ULL
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10ULL;
        count++;
    }
    return count;
}

int getSize(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        //printf("%llu -> ", head->data);   // << print ULL
        head = head->next;
    }
    //printf("\n");
    return count;
}

int main(void) {
    int input[] = {4329, 385, 0, 1444386, 600463, 19, 1, 56615};
    struct node* head = malloc(sizeof(struct node));
    struct node* pointer = head;
    for (int i = 0; i < 7; i++) {
        pointer->data = (unsigned long long)input[i];
        pointer->next = malloc(sizeof(struct node));
        pointer = pointer->next;
    }
    pointer->data = (unsigned long long)input[7];
    pointer->next = NULL;

    for (int i = 0; i < 25; ++i) { //25 or 75 (75 won't work, too much memory usage
        pointer = head;
        while (pointer != NULL) {
            if (pointer->data == 0ULL) {
                pointer->data = 1ULL;
            }
            else if (getNumDigits(pointer->data) % 2 == 0) {
                struct node* newNode = malloc(sizeof(struct node));
                int d = getNumDigits(pointer->data);
                int k = d / 2;

                unsigned long long div = 1;
                for (int t = 0; t < k; ++t) div *= 10ULL;

                unsigned long long right = pointer->data % div;
                unsigned long long left  = pointer->data / div;

                newNode->data = right;
                newNode->next = pointer->next;
                pointer->next = newNode;
                pointer->data = left;

                pointer = newNode;
            }
            else {
                pointer->data *= 2024ULL;
            }
            pointer = pointer->next;
        }
        printf("%d Size: %d\n", i, getSize(head));
    }
    printf("Final Size: %d\n", getSize(head));
    return 0;
}
