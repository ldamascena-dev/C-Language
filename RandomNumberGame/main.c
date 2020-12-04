#include <stdio.h>

int main() {
  printf("************************************* \n");
  printf("* Welcome to the random number game * \n");
  printf("************************************* \n");
 
  int i = 0;
  int secretNumber = 42;
  int userAttempt;
  

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
  }
    
  printf("End! Total: %d attempt(s).\n", i);

  return 0;
}
