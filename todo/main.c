#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Command line todo manager (file-based)
// commands: add list remove

#define FILENAME "todo.txt"
#define TEMPFILE = "temp_todo.txt";

int exists(const char* filename) {
  if (access(filename, F_OK) == 0) {
    printf("File exists...\n");
  } else {
    printf("File doesnt exists... Creating file\n");
    FILE *file = fopen(filename, "a");
    if (file != NULL) {
      fclose(file);
      return 1;
    }
    return 0;
  }
}

int getTaskCount(const char* filename) {
  FILE *file = fopen(filename, "r");

  int count = 0;
  int ch;

  while ((ch = fgetc(file)) != EOF) {
    if (ch == '\n') {
      count++;
    }
  }

  fclose(file);
  return count;
}

char* getLineContentByIndex(const char* filename, int line_number) {
  FILE *file = fopen(filename, "r");
  static char buffer[256];
  int curr_line = 0;

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    if (curr_line == line_number) {
      fclose(file);
      return buffer;
    }

    curr_line++;
  }

  fclose(file);
  return NULL;
}

char* GetStringAfterInt(char* line) {
  char *space = strchr(line, ' ');
  if (space != NULL) {
    return space + 1;
  }
  return line;
}

int main(int argc, char* argv[]) {
  exists(FILENAME);
  FILE *file = fopen(FILENAME, "a+");
  int count = getTaskCount(FILENAME);
  printf("%d\n", count);

  if (argc < 2) {
    return 0;
  }

  if (strcmp(argv[1], "add") == 0) {
    fprintf(file, "%d %s\n", count,argv[2]);
  }
  else if (strcmp(argv[1], "remove") == 0) {
  }
  else if (strcmp(argv[1], "list") == 0) {
    for (int i = 0; i < count; i++) {
      char* full_line = getLineContentByIndex(FILENAME, i);
      if (full_line != NULL) {
        char* taskdisc = GetStringAfterInt(full_line);
        printf("%s", taskdisc);
      }
    }
  }  
}
