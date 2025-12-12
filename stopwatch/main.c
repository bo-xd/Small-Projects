#include <stdio.h>
#include <time.h>

//make stopwatch
// Display live seconds;

int main() {
  time_t start,end;
  double diff_seconds;

  printf("Start stopwatch\n");
  getchar();
  
  time(&start);

  printf("press a key to stopwatch\n");
  getchar();

  time(&end);

  diff_seconds = difftime(end, start);
  printf("Elapsed seconds: %i\n", (int)diff_seconds);

  return 0;
}
