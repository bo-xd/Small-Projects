// password strength checker
// check length uppcase/lowercase digits and special characters


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char password[100];

  int length = 0;
  int upper = 0;
  int lower = 0;
  int special = 0;
  int digit = 0;
  int score = 0;

  printf("Enter a password: ");
  fgets(password, sizeof(password), stdin);
  password[strcspn(password, "\n")] = '\0';
  
  length = strlen(password);

  for (int i = 0; password[i] != '\0'; i++) {
    if (isdigit(password[i])) {
      digit++;
    }
    else if (isupper(password[i])) {
      upper++;
    }
    else if (islower(password[i])) {
      lower++;
    }
    else {
      special = special + 1;
    }
  }

  if (upper < 1 || lower < 1 || special < 1 || digit < 1) {
      printf("Missing:\n");
  }

  if (upper < 1)   printf("- uppercase letter\n");
  if (lower < 1)   printf("- lowercase letter\n");
  if (digit < 1)   printf("- digit\n");
  if (special < 1) printf("- special character\n");

  if (length >= 8) score++;
  if (upper > 0) score++;
  if (lower > 0) score++;
  if (digit > 0) score++;
  if (special > 0) score++;

  if (score <= 2) {
      printf("Strength: WEAK\n");
  } else if (score <= 4) {
      printf("Strength: MEDIUM\n");
  } else {
      printf("Strength: STRONG\n");
  }

  return 0;
}
