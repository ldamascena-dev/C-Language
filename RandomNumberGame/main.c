#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("************************************* \n");
  printf("* Welcome to the random number game * \n");
  printf("************************************* \n");

  short i, isBiggerNumber, isCorrect, level, numberAttempt, userAttempt = 0;
  double lostScore = 0;
  double score = 1000;
  srand(time(0));
  int secretNumber = rand() % 100;

  printf("Select the level \n");
  printf("(1) - Easy\n");
  printf("(2) - Intermediate\n");
  printf("(3) - Hard\n");
  scanf("%d", &level);

  switch (level){

    case 1:
      numberAttempt = 20;
      break;

    case 2:
      numberAttempt = 10;
      break;

    default:
      numberAttempt = 5;
      break;
  }

  for (int i = 1; i <= numberAttempt; i++) {

    printf("Attempt %d\n", i);
    printf("What's the number?\n ");
    scanf("%d", &userAttempt);

    if (userAttempt < 0) {
      printf("Do not use negative numbers!\n");
      i--;
      continue;
    }

    isCorrect = (userAttempt == secretNumber);
    isBiggerNumber = (userAttempt > secretNumber);

    if (isCorrect) {
      break;
    } else if (isBiggerNumber) {
      printf("The number entered is greater than the secret number.\n");
    } else {
      printf("The number entered is less than the secret number.\n");
    }

    lostScore = (userAttempt - secretNumber) / (double) 2;
    score -= fabs(lostScore);
  }

  if (isCorrect) {
    printf("Congratulations, you got it right!\n");
    printf("End! Total: %d attempt(s).\n", i);
    printf("Total Score: %.1f\n", score);
  } else {
    printf("You lost! Try again.\n");
  }

  return 0;
}
