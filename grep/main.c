// remake of "grep" command; 
// search for files inside a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NITEMS(arr) (sizeof(arr) / sizeof(arr)[0])
#define MAX_LINE 1024

int main(int argc, char* argv[]) {

  if (argc < 2) {
    printf("too less arguments used\n");
    return 1;
  }

  FILE* file = fopen(argv[2], "r");
  char line[MAX_LINE];
  char* word = argv[1];

  while (fgets(line, sizeof(line), file)) {
    if (strstr(line, word) != NULL) {
      printf("%s", line);
    }
  }



  fclose(file);
  return 0;
}
