#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMP "temp.txt"
#define MAX_LINE 1024

void rm_line(const char* path, char* string) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    perror("Error opening input file");
    return;
  }

  FILE* temp = fopen(TEMP, "w");
  if (temp == NULL) {
    perror("Error opening temp file");
    fclose(file);
    return;
  }

  char line[MAX_LINE];

  while (fgets(line, sizeof(line), file)) {
    if (strstr(line, string) == NULL) {
      fputs(line, temp);
    }
  }

  fclose(file);
  fclose(temp);
  remove(path);
  rename("temp.txt", path);
  printf("removed all lines with: '%s'\n", string);
}

void rm_word(const char* path, const char* word_to_remove) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        perror("Error opening input file");
        return;
    }
    
    FILE* temp = fopen(TEMP, "w");
    if (temp == NULL) {
        perror("Error opening temp file");
        fclose(file);
        return;
    }

    char line[MAX_LINE];
    char modified_line[MAX_LINE];
    char* found;
    size_t word_len = strlen(word_to_remove);

    while (fgets(line, sizeof(line), file)) {
        char* current_read = line;
        
        modified_line[0] = '\0'; 

        while ((found = strstr(current_read, word_to_remove)) != NULL) {
            *found = '\0'; 
            strcat(modified_line, current_read);
            
            current_read = found + word_len;
        }

        strcat(modified_line, current_read);

        fputs(modified_line, temp);
    }

    fclose(file);
    fclose(temp);
    printf("removed the word: '%s'\n", string);
    
}

int main(int argc, char* argv[]) {

  if (argc < 2) {
    printf("no args?");
    return 1;
  }

  if ((strcmp(argv[1], "-l") == 0) || (strcmp(argv[1], "-line") == 0)) {
    rm_line(argv[2], argv[3]);
  } else if ((strcmp(argv[1], "-w") == 0) || (strcmp(argv[1], "-word")) == 0) {
    rm_word(argv[2], argv[3]);
  } else {
    printf("huh");
  }

 return 0; 
}
