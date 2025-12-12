#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]) {
  bool disablenewline = false;
  int start = 1;
  if (argc > 1 && strcmp(argv[1], "-n") == 0) {
    disablenewline = true;
    start = 2;
  }

  for (int i = start; i < argc; i++) {
    printf("%s", argv[i]);

    if (i < argc - 1){
      printf(" ");
    }
  }

  if (!disablenewline) {
    printf("\n");
  }

  return 0;
}
