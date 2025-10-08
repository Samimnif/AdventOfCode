//
// Created by sami mnif on 2025-10-07.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Check if the numbers are ascending
 * @param l
 * @param size
 * @return true if the numbers are ascending, false otherwise.
 */
bool checkAsc(int* l, int size) {
    for (int i = 0; i < size; i++) {
        if (l[i] > l[i+1]) {
            return false;
        }
    }
    return true;
}

/**
 * Check if the numbers are descending
 * @param l
 * @param size
 * @return true if the numbers are descending, false otherwise.
 */
bool checkDesc(int* l, int size) {
    for (int i = 0; i < size; i++) {
        if (l[i] < l[i+1]) {
            return false;
        }
    }
    return true;
}

/**
 * Check if the difference between each numbers are between 1 to 3
 * @param l
 * @param size
 * @return true if the differences are good, false otherwise
 */
bool checkDiff(int* l, int size) {
    for (int i = 0; i < size; ++i) {
        int diff = abs(l[i] - l[i+1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

/**
 * Goes through the list of numbers and makes the checks and returns if it is safe or not
 * @param l : list header
 * @return True if safe, otherwise false
 */
bool splitList(char* l) {
    int space_count = 0;
    for (int i = 0; i < strlen(l); i++) {
        if (l[i] == ' ') {
            space_count++;
        }
    }
    //space_count += 1;
    int reports[space_count];
    char* token = strtok(l, " ");

    int i = 0;
    while (token != NULL) {
        reports[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    printf("%hhd, %hhd, %hhd\n", checkAsc(reports, space_count), checkDesc(reports, space_count), checkDiff(reports, space_count));
    if (checkDiff(reports, space_count)) {
        if (checkAsc(reports, space_count) || checkDesc(reports, space_count)) {
            return true;
        }
    }
    return false;
}

int main(void) {

    FILE *fptr = fopen("./Day2/input.txt", "r"); //depends on where you run your .exe

    char buff[50];
    int count = 0;

    // Reading strings till fgets returns NULL
    while (fgets(buff, 50, fptr)) {
        printf("%s", buff);
        if (splitList(buff)) {
            count++;
        }
    };
    printf("Safe Reports: %d\n", count);
    fclose(fptr);
    fclose(fptr);
    return 0;
}
