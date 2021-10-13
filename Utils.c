#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Utils.h"

// TODO: garbage collection of buffer? atexit
char* getString(const char* message) {
    // Prompt the user.
    printf("%s", message);

    // Buffer for user input.
    char *result = NULL;

    // Record the user input.
    int i;
    for (i = 0; 1; i++) {
        // Resize buffer as needed (per character).
        // TODO: is this good?
        result = realloc(result, i + 1);
        if (result == NULL) {
            printf("AN ERROR OCCURRED: FAILED TO ALLOCATE MEMORY\n");
            _getch();
            exit(2);
        }

        // Character input.
        char c = _getch();

        // Handle escape.
        if (c == '\e') {
            result[i] = '\0';
            break;
        }

        // Handle deletion.
        if (c == '\b') {
            if (i > 0) {
                i -= 2;

                printf("\b \b");
            }
            continue;
        }

        // Handle newline.
        if (c == '\r') {
            c = '\n';
        }

        // Record character in the string.
        result[i] = c;

        // Echo the character that the user just input.
        printf("%c", c);
    }

    return result;
}