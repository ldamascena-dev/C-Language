#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

char kicks[26];
char secretWord[20];
short attempts = 0;

void opening() {
  printf(" ****************\n");
  printf(" *  HangmanGame *\n");
  printf(" ****************\n\n");
}

void selectWord() {
  FILE * file;

  file = fopen("words.txt", "r");

  if (file == 0) {
    printf("File not found\n\n");
    exit(1);
  }

  int numberOfWords;
  fscanf(file, "%d", &numberOfWords);
  srand(time(0));

  int randomNumber = rand() % numberOfWords;

  for (int i = 0; i <= randomNumber; i++) {
    fscanf(file, "%s", secretWord);
  }

  fclose(file);
}

void drawGame() {

  short errors = wrongKicks();

  printf("  _______       \n");
  printf(" |/      |      \n");
  printf(" |      %c%c%c  \n", (errors >= 1 ? '(' : ' '), (errors >= 1 ? '_' : ' '), (errors >= 1 ? ')' : ' '));
  printf(" |      %c%c%c  \n", (errors >= 3 ? '\\' : ' '), (errors >= 2 ? '|' : ' '), (errors >= 3 ? '/' : ' '));
  printf(" |       %c     \n", (errors >= 2 ? '|' : ' '));
  printf(" |      %c %c   \n", (errors >= 4 ? '/' : ' '), (errors >= 4 ? '\\' : ' '));
  printf(" |              \n");
  printf("_|___           \n");
  printf("\n\n");

  for (int i = 0; i < strlen(secretWord); i++) {
    if (alreadyKicked(secretWord[i])) {
      printf("%c ", secretWord[i]);
    } else {
      printf("_ ");
    }
  }
  printf("\n\n");
}


int wrongKicks(){
  short errors = 0;

  for (int i = 0; i < attempts; i++) {
    if (!isLetterExist(kicks[i])) {
      errors++;
    }
  }

  return errors;
}

int isLetterExist(char letter) {

  for (int i = 0; i < strlen(secretWord); i++) {
    if (secretWord[i] == letter) {
      return 1;
    }
  }

  return 0;
}

void letterKick() {
  char letter;

  printf("\n");
  printf("Type a letter: ");
  scanf(" %c", &letter);

  if(isLetterExist(letter)){
    printf("You're right!\n\n");
  }else{
    printf("You missed!\n\n");
  }

  kicks[attempts] = letter;
  attempts++;
}

int alreadyKicked(char letter){
  short find = 0;

      for(int j = 0; j < attempts; j++) {
        if(kicks[j] == letter) {
            find = 1;
            break;
        }
    }
    return find;
}

int isWinner(){
      for(int i = 0; i < strlen(secretWord); i++) {
        if(!alreadyKicked(secretWord[i])) {
            return 0;
        }
    }
    return 1;
}

int isHanged(){
  return wrongKicks() >= 5;
}

int main() {
  opening();
  selectWord();

  do {
    drawGame();
    letterKick();
  } while (!isWinner() && !isHanged());

  if(isWinner()){
    printf("Congratulations you got the word right!\n\n");
  }else{
    printf("Oh no! Unfortunately you lost!\n\n");
    printf("The word was: %s\n\n", secretWord);
  }
}