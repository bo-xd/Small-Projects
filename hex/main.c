#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  FILE* file;
  long filesize;
  char *buffer, *it;
  int byte_count = 0;
  const int bytesrow = 10;

  if ((file = fopen(argv[1], "rb")) == NULL) {
    printf("error opening file\n");
    return 1;
  }

  fseek(file, 0, SEEK_END);
  filesize = ftell(file);
  rewind(file);

  buffer = (char *)malloc(sizeof(char) * filesize + 1);
  if (fread(buffer, sizeof(char), filesize, file) != filesize) {
    printf("error reading file\n");
    return 1;
  }

  fclose(file);

  buffer[filesize] = '\0';

  for (it = buffer; byte_count < filesize; it++, byte_count++) {
    if (byte_count > 0 && (byte_count % bytesrow) == 0) {
      printf("\n");
    }
  
    printf("%02X ", (unsigned char)*it);
  }

  free(buffer);

  return 0;
}
