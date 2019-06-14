#include <stdio.h>

int main(int argc, char const *argv[])
{
  char info[80];
  float lati;
  float longi;

  int started = 0;

  puts("data=[");

  while (scanf("%f,%f,%79[^\n]", &lati, &longi, info) == 3)
  {
    if (started)
      puts(",");
    else
      started = 1;

    printf("{latitude: %f, longitude: %f, info: '%s'}", lati, longi, info);
  }

  puts("\n]");
  return 0;
}
