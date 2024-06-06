#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

size_t maxSeq(int* array, size_t n) {
    size_t result = 0;
    size_t curr = 0;
    int prev = INT_MIN;

    for (size_t i = 0; i < n; i++) {
        if (array[i] > prev) {
            curr++;
        }
        else {
            curr = 1;
        }
        if (curr > result) {
            result = curr;
        }
        prev = array[i];
    }

    return result;
}