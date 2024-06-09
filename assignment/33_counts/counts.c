#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
    //WRITE ME
    counts_t* c = malloc(sizeof(*c));
    c->counts = NULL;
    c->size = 0;
    c->unknown = 0;
    return c;
}

void addCount(counts_t* c, const char* name) {
    //WRITE ME
    if (name == NULL) {
        c->unknown++;
        return;
    }

    for (int i = 0; i < c->size; i++) {
        if (strcmp(name, c->counts[i].str) == 0) {
        c->counts[i].count++;
        return;
        }
    }

    one_count_t * newCount = malloc(sizeof(one_count_t));
    newCount->str = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(newCount->str, name);
    newCount->count = 1;
    c->counts = realloc(c->counts, (c->size + 1) * sizeof(one_count_t));
    c->counts[c->size] = *newCount;
    c->size++;
    free(newCount);
}
void printCounts(counts_t * c, FILE * outFile) {
    //WRITE ME
    for (int i = 0; i < c->size; i++) {
        fprintf(outFile, "%s: %d\n", c->counts[i].str, c->counts[i].count);
    }
    if (c->unknown) {
        fprintf(outFile, "<unknown> : %d\n", c->unknown);
    }
    if (fclose(outFile) != 0) {
        fprintf(stderr, "Couldn't close the file!\n");
    }
}

void freeCounts(counts_t * c) {
    //WRITE ME
    for (int i = 0; i < c->size; i++) {
        free(c->counts[i].str);
    }
    free(c->counts);
    free(c);
}
