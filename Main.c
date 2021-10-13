#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <direct.h>
#include <time.h>
#include "Utils.h"

int main(void) {
    // For storing text.
    char *content;
    
    // User inputs the text.
    // TODO: consider newline character.
    content = getString("Content:\n");
    
    // Open a file within a subdirectory for saving.
    _mkdir(".\\Entries");
    FILE *fptr = fopen(".\\Entries\\entry.txt", "a");
    if (fptr == NULL) {
        printf("AN ERROR OCCURRED: FAILED TO OPEN FILE\n");
        _getch();
        exit(1);
    }

    // Save the text with a timestamp.
    // TODO: the string returned from ctime?
    time_t rawtime = time(NULL);
    fprintf(fptr, "%s", ctime(&rawtime));
    fprintf(fptr, "%s\n", content);
    fclose(fptr);

    // Must free the buffer.
    free(content);

    printf("TEXT SUCCESSFULLY SAVED\n");
    _getch();
    exit(0);
}