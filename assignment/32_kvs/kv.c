#define _GNU_SOURCE


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



char *splitLine2KV(char *line, const char *delim) {
    char *v = strstr(line, delim);

    if (v == NULL)
        return NULL;
    *v = '\0';
    v = v + strlen(delim);
    strtok(v, "\n");
    char *ans = malloc((strlen(v) + 1) * sizeof(*ans));
    strcpy(ans, v);
    // return v + strlen(delim);
    return ans;
}

kvarray_t *readKVs(const char *fname) {
    FILE *f = fopen(fname, "r");
    if (f == NULL) {
        fprintf(stderr, "Could not open file\n");
        return NULL;
    }

    kvarray_t *kvArray = malloc(sizeof(*kvArray));
    kvArray->array = NULL;
    kvArray->size = 0;
    char *line = NULL;
    size_t sz = 0;
    int i = 0;
    char *v = NULL;

    while (getline(&line, &sz, f) >= 0) {
        v = splitLine2KV(line, "=");
        if (v) {
        kvpair_t *kvPair = malloc(sizeof(*kvPair));
        kvPair->key = malloc((strlen(line) + 1) * sizeof(kvPair->key));
        kvPair->value = malloc((strlen(v) + 1) * sizeof(kvPair->value));
        strcpy(kvPair->key, line);
        strcpy(kvPair->value, v);
        kvArray->array = realloc(kvArray->array, (i + 1) * sizeof(kvpair_t));
        kvArray->array[i] = *kvPair;
        i++;
        kvArray->size = i;
        free(kvPair);
        }
        free(v);
    }
    free(line);

    if (fclose(f) != 0) {
        fprintf(stderr, "Could not close file\n");
        return NULL;
    }

    return kvArray;
}


void freeKVs(kvarray_t * pairs) {
    //WRITE ME
    for (size_t i = 0; i < pairs->size; i++) {
        free(pairs->array[i].key);
        free(pairs->array[i].value);
    }
    free(pairs->array);
    free(pairs);
}

void printKVs(kvarray_t * pairs) {
    //WRITE ME
    for (size_t i = 0; i < pairs->size; i++) {
        printf("key = '%s' value = '%s'\n", pairs->array[i].key, pairs->array[i].value);
    }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
    //WRITE ME
    for (size_t i = 0; i < pairs->size; i++) {
        if (strcmp(pairs->array[i].key, key) == 0) {
            return pairs->array[i].value;
        }
    }
    return NULL;
}
