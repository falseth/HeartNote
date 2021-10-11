#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <direct.h>

int main(void) {
    // For storing text.
    char content[1024];

    // User inputs the text.
    // TODO: prone to buffer overflow.
    printf("Content:\n");
    scanf("%s", content);
    
    // Save the text in a file within a subdirectory.
    _mkdir(".\\Entries");
    FILE *fptr = fopen(".\\Entries\\entry.txt", "w");
    if (fptr == NULL) {
        printf("AN ERROR OCCURRED!\n");
        _getch();
        exit(1);
    }
    fprintf(fptr, "%s", content);
    fclose(fptr);

    _getch();
    exit(0);
}