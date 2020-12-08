#include <stdio.h>
#include <string.h>

int main()
{
    char letter;
    char kicks[26];
    char secretWord[20];
    sprintf(secretWord, "MELANCIA");

    short attempts = 0;
    short isCorrect = 0;
    short isFoundWord = 0;
    short isHanged = 0;

    do
    {
        for(int i=0; i < strlen(secretWord); i++)
        {
            isFoundWord = 0;

            for(int j=0; j < attempts; j++){
                if(kicks[j] == secretWord[i])
                {
                    isFoundWord = 1;
                    break;
                }
            }

            if(isFoundWord)
            {
                printf("%c ", secretWord[i]);
            }
            else
            {
                printf("_ ");
            }
        }

        printf("\n");
        printf("Type a letter: ");
        scanf(" %c", &letter);

        kicks[attempts] = letter;
        attempts++;

    } while(!isCorrect && !isHanged);
    
    return 0;
}