#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
    const char * const * p1 = vp1;
    const char * const * p2 = vp2;
    return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
    qsort(data, count, sizeof(char *), stringOrder);
}

void printData(char** strs, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%s", strs[i]);
        free(strs[i]);
    }
}

void readStr(FILE* f) {
    char** strs = NULL;
    char* line = NULL;
    size_t sz = 0;
    size_t count = 0;
    while (getline(&line, &sz, f) >= 0) {
        strs = realloc(strs, (count + 1) * sizeof(*strs));
        strs[count] = line;
        line = NULL;
        count++;
    }
    free(line);
    sortData(strs, count);
    printData(strs, count);
    free(strs);
}

int main(int argc, char** argv) {
    //WRITE YOUR CODE HERE!
    if (argc == 1) {
        readStr(stdin);
    }
    else {
        for (int i = 1; i < argc; i++) {
            FILE* f = fopen(argv[i], "r");
            if (f == NULL) {
                perror("Could not open file");
                return EXIT_FAILURE;
            }
            readStr(f);
            if (fclose(f) != 0) {
                fprintf(stderr, "File could not close properly\n");
                return EXIT_FAILURE;
            }
        }
    }
        return EXIT_SUCCESS;
}
