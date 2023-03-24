#include <stdio.h>
#include <stdlib.h>
#define MEMORY_BLOCK 10

void writeFile();
void readFile();

int main()
{

    char *filepath = malloc(255);
    char *textToAdd = malloc(255);
    char *actionNumber = malloc(255);

    printf("%s\n%s\n", "Simple file manager by EKKI", "Type the number for the action");

    printf("%s\n%s\n", "1: Write", "2: Read");

    fgets(actionNumber, 255, stdin);

    switch (*actionNumber)
    {
    case '1':
        printf("%s\n", "Enter the file path :");
        fgets(filepath, 255, stdin);
        printf("filepath : %s\n", filepath);

        printf("%s\n", "Enter the text to add :");
        fgets(textToAdd, 255, stdin);
        printf("textToAdd : %s\n", textToAdd);

        writeFile(&filepath, &textToAdd);
        break;

    case '2':
        printf("%s\n", "Enter the file path :");
        filepath = "";
        fgets(filepath, 255, stdin);

        readFile(filepath);
        break;

    default:
        printf("%s\n", "Invalid");
        break;
    }

    free(filepath);
    free(textToAdd);
    free(actionNumber);

    return 0;
}
void writeFile(char *filepath, char *textToAdd)
{

    FILE *ptrToFile = NULL;

    ptrToFile = fopen("test2.txt", "w");

    printf("11%s", textToAdd);

    fputs(textToAdd, ptrToFile);

    fclose(ptrToFile);
}

void readFile(char *filepath)
{

    printf("%s", filepath);

    FILE *ptrToFile = NULL;

    ptrToFile = fopen(filepath, "r");

    char fileContent[100];

    fgets(fileContent, 255, ptrToFile);

    printf("%s", fileContent);

    fclose(ptrToFile);
}