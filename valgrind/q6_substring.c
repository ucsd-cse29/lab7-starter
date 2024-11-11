#include "jstr.c"


// This one has a subtle bug. There isn't really a one-line fix for this,
// but can you use valgrind to figure out the issue?
String substring2(String s, int start, int end) {
    assert(start >= 0);
    assert(end <= s.length);
    assert(start <= end);
    
    // Make a copy of s.contents for us to substringify
    char* s_copy = malloc(s.length + 1);
    strcpy(s_copy, s.contents);

    int new_length = end - start;

    // Get a pointer to substring at start index
    char *substring_start = s_copy + start;
    // Terminate our copy at index `end`
    s_copy[end] = 0;

    String r = { new_length, substring_start };
    return r;
}

int main() {
    
    String abcdef2 = new_String("abcdef");
    String def2 = substring2(abcdef2, 3, 6);
    printf("%s\n", def2.contents);
    free(def2.contents);
    free(abcdef2.contents);
}
