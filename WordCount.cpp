#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];
    FILE *file;
    char ch;
    int char_count = 0;
    int word_count = 0;
    int in_word = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        char_count++;

        // Check if the character is a space, tab, or newline
        if (isspace(ch)) {
            if (in_word) {
                in_word = 0;
                word_count++;
            }
        } else {
            in_word = 1;
        }
    }

    // Count the last word if it's not followed by a space, tab, or newline
    if (in_word) {
        word_count++;
    }

    fclose(file);

    if (strcmp(parameter, "-c") == 0) {
        printf("×Ö·ûÊý: %d\n", char_count);
    } else if (strcmp(parameter, "-w") == 0) {
        printf("µ¥´ÊÊý: %d\n", word_count);
    } else {
        printf("Invalid parameter. Use -c or -w.\n");
        return 1;
    }

    return 0;
}

