//
// Created by sami mnif on 2025-10-06.
//

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Sorts the list to asc order
 * @param l : List pointer
 * @param max_n : max size
 */
void sortList(int* l, int max_n) {
    bool unsorted = true;
    int i = 0;
    while (unsorted) {
        unsorted = false;
        i = 0;
        while (i < max_n-1) {
            if (l[i] > l[i + 1]) {
                int tmp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = tmp;
                unsorted = true;
            }
            i++;
        }
    }
}

/**
 * Checks how many similar num exists
 * @param l : Left list pointer
 * @param r : Right list pointer
 * @param max_n : Max size of the lists
 * @return sum of all similar numbers encountered
 */
int similarity(int* l, int* r, int max_n) {
    int count = 0, sum = 0;
    for (int i = 0; i < max_n; i++) {
        count = 0;
        for (int j = 0; j < max_n; j++) {
            if (l[i] == r[j]) {
                count++;
            }
        }
        sum += count*l[i];
    }
    return sum;
}


int main(void) {
    FILE *fptr = fopen("./Day1/input.txt", "r"); //depends on where you run your .exe

    // Variables for storing data
    int list1[1000];
    int list2[1000];

    int n = 0;

    int totalDistance = 0;

    while (fscanf(fptr, "%d %d", &list1[n], &list2[n]) == 2) {
        n++; //count the size of the list too
    }
    fclose(fptr);
    int sim = similarity(list1, list2, n); //Part 2

    sortList(list1, n); //sort left list
    sortList(list2, n); //sort right list
    for (int i = 0; i < n; i++) {
        printf("List1: %d\t List2: %d\n", list1[i], list2[i]);
        totalDistance += abs(list1[i] - list2[i]);
    }
    printf("Total distance: %d\n", totalDistance); //Part 1
    printf("Similarity: %d\n", sim); //Part 2
    return 0;
}
