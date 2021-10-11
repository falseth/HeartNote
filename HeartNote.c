#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <direct.h>
#include <time.h>

#define MAX_SIZE 1024

int main(void) {
    // For storing text.
    char content[MAX_SIZE];

    // User inputs the text.
    // TODO: consider newline character.
    printf("Content:\n");
    fgets(content, MAX_SIZE, stdin);
    
    // Open a file within a subdirectory for saving.
    _mkdir(".\\Entries");
    FILE *fptr = fopen(".\\Entries\\entry.txt", "a");
    if (fptr == NULL) {
        printf("AN ERROR OCCURRED\n");
        _getch();
        exit(1);
    }

    // Save the text with a timestamp.
    time_t rawtime = time(NULL);
    fprintf(fptr, "%s", ctime(&rawtime));
    fprintf(fptr, "%s\n", content);
    fclose(fptr);

    printf("TEXT SUCCESSFULLY SAVED\n");
    _getch();
    exit(0);
}