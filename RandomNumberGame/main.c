#include <stdio.h>

#define ATTEMPT_NUMBER 3

int main() {
  printf("************************************* \n");
  printf("* Welcome to the random number game * \n");
  printf("************************************* \n");
 
  int secretNumber = 42;
  int userAttempt;

  for (int i = 1; i <= ATTEMPT_NUMBER; i++) {
    printf("Attempt %d of %d\n", i, ATTEMPT_NUMBER);  
    printf("What's the number? ");
    scanf("%d", &userAttempt);

    if(userAttempt < 0){
      printf("Do not use negative numbers!\n");
      i--;
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
  }
    
  printf("End!\n");

  return 0;
}
