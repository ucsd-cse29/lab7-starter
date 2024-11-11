#include "arraylist.c"

// Should return a copy of the list, with copies of the strings
List buggy_slice(List a, uint32_t start, uint32_t end) {
    assert(start >= 0);
    assert(start <= end);
    assert(end <= a.size);

    List b = new_List();

    for (uint32_t i = start; i < end; i += 1) {
        append1(&b, a.contents[i]);
    }

    return b;

}

int main() {
    List a = new_List();
    append1(&a, new_String("apple"));
    append1(&a, new_String("banana"));
    append1(&a, new_String("cranberry"));
    append1(&a, new_String("doughnut"));

    List b = buggy_slice(a, 1, 3);

    printf("Original list:\n");
    for (int i = 0; i < a.size; i += 1) { 
        printf("- %s (at addr %p)\n", a.contents[i].contents, a.contents[i].contents); 
    }

    printf("Sliced list:\n");
    for (int i = 0; i < b.size; i += 1) { 
        printf("- %s (at addr %p)\n", b.contents[i].contents, b.contents[i].contents); 
    }


    // Now we need to free the strings in a and b
    for (int i = 0; i < a.size; i += 1) {
        free(a.contents[i].contents);
    }
    free(a.contents);

    for (int i = 0; i < b.size; i += 1) {
        free(b.contents[i].contents);
    }
    free(b.contents);
}
