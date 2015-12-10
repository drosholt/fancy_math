#include <stdio.h>
#include <time.h>

void report_time(const char *prefix, int id, int occurrence) {
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );

  timeinfo = localtime ( &rawtime );
  printf ("%d|%d|%s|%s", id, occurrence, prefix, asctime(timeinfo));
}
