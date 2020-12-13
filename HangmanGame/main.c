#include <stdio.h>
#include <string.h>

char kicks[26];
char secretWord[20];
short attempts = 0;

void opening() {
  printf(" ****************\n");
  printf(" *  HangmanGame *\n");
  printf(" ****************\n\n");
}

void letterKick() {
  char letter;
  printf("\n");
  printf("Type a letter: ");
  scanf(" %c", &letter);

  kicks[attempts] = letter;
}

int scanningKicks(char letter) {
  short isFoundWord = 0;

    for (int j = 0; j < attempts; j++) {
      if (kicks[j] == letter) {
        isFoundWord = 1;
        break;
      }
    }
  
    return isFoundWord;
}

void drawGame() {
  printf("You are in attempt: %d\n ", attempts);

  for (int i = 0; i < strlen(secretWord); i++) {
    if (scanningKicks(secretWord[i])) {
      printf("%c ", secretWord[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n");
}

void selectWord() {
  sprintf(secretWord, "MELANCIA");
}

int main() {
  short isCorrect = 0;
  short isHanged = 0;

  opening();
  selectWord();

  do {
    drawGame();
    letterKick();
    attempts++;
  } while (!isCorrect && !isHanged);
}
