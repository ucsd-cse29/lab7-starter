#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "jstr.c"

struct List {
    uint32_t size;
    uint32_t capacity;
    String* contents;
};
typedef struct List List;

// NOTE: The default capacity of a new list is 2
List new_List() {
    List a = { 0, 2, calloc(2, sizeof(String)) };
    return a;
}

void expandCapacity(List* a) {
    uint32_t new_cap = a->capacity * 2;
    a->capacity = new_cap;
    a->contents = realloc(a->contents, new_cap * sizeof(String));
}

void append1(List *a, String value) {
    if(a->size + 1 >= a->capacity) {
        expandCapacity(a);
    }
    a->contents[a->size] = value;
    a->size += 1;
}

