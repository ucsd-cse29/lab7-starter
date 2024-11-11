#include "arraylist.c"

// Use valgrind to determine where the memory leak is in this program and fix it!

void buggy_expandCapacity(List* a) {
    uint32_t new_cap = a->capacity * 2;
    String* new_ptr = calloc(new_cap, sizeof(String));
    memcpy(new_ptr, a->contents, a->size * sizeof(String));

    a->capacity = new_cap;
    a->contents = new_ptr;
}

void buggy_append1(List *a, String value) {
    if(a->size + 1 == a->capacity) {
        buggy_expandCapacity(a);
    }
    a->contents[a->size] = value;
    a->size += 1;
}

int main() {

    // Create a new list and add 5 strings to it
    List a = new_List();
    buggy_append1(&a, new_String("apple"));
    buggy_append1(&a, new_String("banana"));
    buggy_append1(&a, new_String("cranberry"));
    buggy_append1(&a, new_String("doughnut"));
    buggy_append1(&a, new_String("eggplant"));


    for (int i = 0; i < a.size; i += 1) {
        printf("%s\n", a.contents[i].contents);
    }

    for (int i = 0; i < a.size; i += 1) {
        free(a.contents[i].contents);
    }
    free(a.contents);
}
