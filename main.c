#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Insert a line */
void insertLine(int position, char text[])
{
    int i;

    if (position < 1 || position > lineCount + 1)
    {
        printf("Invalid line number!\n");
        return;
    }

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full!\n");
        return;
    }

    for (i = lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);
    lineCount++;

    printf("Line inserted successfully!\n");
}

/* Delete a line */
void deleteLine(int position)
{
    int i;

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number!\n");
        return;
    }

    for (i = position - 1; i < lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully!\n");
}

/* Display document */
void displayDocument()
{
    int i;

    if (lineCount == 0)
    {
        printf("\nDocument is empty!\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Search for a word */
void searchWord()
{
    char word[MAX_LENGTH];
    int i;
    int found = 0;

    if (lineCount == 0)
    {
        printf("\nDocument is empty!\n");
        return;
    }

    printf("Enter word to search: ");
    fgets(word, MAX_LENGTH, stdin);

    word[strcspn(word, "\n")] = '\0';

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], word) != NULL)
        {
            printf("Word found in line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Word not found in the document.\n");
    }
}

/* Display total line count */
void displayLineCount()
{
    printf("\nTotal number of lines: %d\n", lineCount);
}

/* Count total words */
void displayWordCount()
{
    int i, j;
    int words = 0;
    int inWord;

    for (i = 0; i < lineCount; i++)
    {
        inWord = 0;

        for (j = 0; lines[i][j] != '\0'; j++)
        {
            if (!isspace((unsigned char)lines[i][j]))
            {
                if (!inWord)
                {
                    words++;
                    inWord = 1;
                }
            }
            else
            {
                inWord = 0;
            }
        }
    }

    printf("\nTotal number of words: %d\n", words);
}

/* Additional Features Menu */
void additionalFeatures()
{
    int choice;

    while (1)
    {
        printf("\n===== ADDITIONAL FEATURES =====\n");
        printf("1. Search a Word\n");
        printf("2. Line Count\n");
        printf("3. Word Count\n");
        printf("4. Back to Main Menu\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            searchWord();
        }
        else if (choice == 2)
        {
            displayLineCount();
        }
        else if (choice == 3)
        {
            displayWordCount();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
}

/* Main function */
int main()
{
    int command;
    int position;
    char text[MAX_LENGTH];

    printf("===== SIMPLE LINE EDITOR =====\n");

    while (1)
    {
        printf("\n1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Additional Features\n");
        printf("5. Quit\n");

        printf("\nEnter command: ");
        scanf("%d", &command);
        getchar();

        if (command == 1)
        {
            printf("Enter line number: ");
            scanf("%d", &position);
            getchar();

            printf("Enter text: ");
            fgets(text, MAX_LENGTH, stdin);

            text[strcspn(text, "\n")] = '\0';

            insertLine(position, text);
        }
        else if (command == 2)
        {
            printf("Enter line number: ");
            scanf("%d", &position);
            getchar();

            deleteLine(position);
        }
        else if (command == 3)
        {
            displayDocument();
        }
        else if (command == 4)
        {
            additionalFeatures();
        }
        else if (command == 5)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid command!\n");
        }
    }

    return 0;
}