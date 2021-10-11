#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <direct.h>

#define MAX_SIZE 1024

int main(void) {
    // For storing text.
    char content[MAX_SIZE];

    // User inputs the text.
    printf("Content:\n");
    fgets(content, MAX_SIZE, stdin);
    
    // Save the text in a file within a subdirectory.
    _mkdir(".\\Entries");
    FILE *fptr = fopen(".\\Entries\\entry.txt", "w");
    if (fptr == NULL) {
        printf("AN ERROR OCCURRED\n");
        _getch();
        exit(1);
    }
    fprintf(fptr, "%s", content);
    fclose(fptr);

    printf("TEXT SUCCESSFULLY SAVED\n");
    _getch();
    exit(0);
}