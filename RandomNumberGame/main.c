#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("************************************* \n");
  printf("* Welcome to the random number game * \n");
  printf("************************************* \n");
 
  int i = 0;
  double lostScore = 0;
  double score = 1000;
  srand(time(0));
  int secretNumber = rand() % 100;
  int userAttempt = 0;
  
  while (1) {
    
    i++;
    
    printf("Attempt %d\n", i);  
    printf("What's the number? ");
    scanf("%d", &userAttempt);

    if(userAttempt < 0){
      printf("Do not use negative numbers!\n");
      continue;
    }

    int IsCorrect = (userAttempt == secretNumber);
    int isBiggerNumber = (userAttempt > secretNumber);

    if (IsCorrect) {
      printf("Congratulations, you got it right!\n");
      break;
    } else if (isBiggerNumber) {
        printf("The number entered is greater than the secret number.\n");
    } else {
        printf("The number entered is less than the secret number.\n");
    }

    lostScore = (userAttempt - secretNumber) / (double) 2;
    score -= fabs(lostScore);
  }
    
  printf("End! Total: %d attempt(s).\n", i);
  printf("Total Score: %.1f\n", score);

  return 0;
}
