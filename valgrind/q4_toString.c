#include "arraylist.c"

String buggy_toString(List l) {
    // Join all strings with commas
    String str_1 = join(l.contents, l.size, new_String(", "));

    // Add brackets
    String lbracket = new_String("[");
    String rbracket = new_String("]");
    String str_2 = plus(lbracket, str_1); // with [
    String str_3 = plus(str_2, rbracket); // with [ and ]
    
    // Free our intermediate strings
    free(str_1.contents);
    free(str_2.contents);
    free(lbracket.contents);
    free(rbracket.contents);

    return str_3; 
}

int main() {
    List a = new_List();
    append1(&a, new_String("apple"));
    append1(&a, new_String("banana"));
    append1(&a, new_String("cranberry"));
    append1(&a, new_String("doughnut"));
    append1(&a, new_String("eggplant"));

    String s = buggy_toString(a);

    printf("List contains: %s\n", s.contents);

    // Free our string
    free(s.contents);

    // Free the list and its contents
    for (int i = 0; i < a.size; i += 1) {
        free(a.contents[i].contents);
    }
    free(a.contents);
}
