#include "arraylist.c"

// Function to free the list and its contents
void buggy_freeListAndContents(List a) {
    free(a.contents); 

    for (int i = 0; i < a.size; i += 1) {
        free(a.contents[i].contents);
    }
}

int main() {
    List l = new_List();
    append1(&l, new_String("apple"));
    append1(&l, new_String("banana"));
    append1(&l, new_String("cranberry"));
    append1(&l, new_String("doughnut"));
    append1(&l, new_String("eggplant"));

    for (int i = 0; i < l.size; i += 1) {
        printf("%s\n", l.contents[i].contents);
    }

    buggy_freeListAndContents(l);
}
