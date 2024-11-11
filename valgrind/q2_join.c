#include "jstr.c"

String buggy_join(String strs[], int count, String delimiter) {
    int total_length = 0;

    // Start with an empty string
    char *new_contents = malloc(1);
    new_contents[0] = '\0';

    for(int i = 0; i < count; i += 1) {
        // Hold onto old contents to copy over
        char *old_contents = new_contents;

        // Allocate space to add the next string, possibly a delimiter + nullterm
        new_contents = malloc(total_length + strs[i].length + delimiter.length + 1);

        // Copy in previous value of contents
        strcpy(new_contents, old_contents);

        // Copy in strs[i], adjust length
        strcpy(new_contents + total_length, strs[i].contents);
        total_length += strs[i].length;

        // Copy in delimiter, adjust length
        if(i < count - 1) {
            strcpy(new_contents + total_length, delimiter.contents);
            total_length += delimiter.length;
        }

    }

    // strcpy should have put a null terminator already
    String r = { total_length, new_contents };
    return r;
}

int main() {
    String apple = new_String("apple");
    String banana = new_String("banana");
    String strawberry = new_String("strawberry");

    String fruit[] = { apple, banana, strawberry };

    String comma = new_String(", ");
    String fruits = buggy_join(fruit, 3, comma);

    printf("%s\n", fruits.contents);

    // Need to free these so valgrind doesn't complain
    // (not actually a problem in normal programs, since we're going to exit)
    free(comma.contents);
    free(apple.contents);
    free(banana.contents);
    free(strawberry.contents);
    free(fruits.contents);
}
