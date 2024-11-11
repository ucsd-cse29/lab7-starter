#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "secret.h"

long unsigned hash_word(char* secret) {
        
    unsigned long hash = 5381;
    int c;

    while ((c = *secret++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int main() {
    const char *username = getenv("USER");

    printf("Generating and hashing secret password for \"%s\"...\n", username);
    char* password = get_secret(username);

    long unsigned hash = hash_word(password);
    printf("the hash is 0x%lx\n", hash);
    char buffer[20];
    printf("What is the password?: \n");
    do
    {
        fgets(buffer, 20, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  //Sets the trailing \n from fgets to \0

        if (hash_word(buffer) == hash) {
            printf("PASSWORD CRACKED!!! Found Password: %s\n", buffer);
            return 0;
        }
        printf("Password not found, Try again \n");
    } while (buffer[0] != '\0');
    printf("PASSWORD NOT FOUND.\n");
    return 0;
}
