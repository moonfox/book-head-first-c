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

    if ((lati < -90.0) || (lati > 90.0))
    {
      fprintf(stderr, "invalid latitude: %f\n", lati);
      return 2;
    }

    if ((longi < -180.0) || (longi > 180.0))
    {
      fprintf(stderr, "invalid longitude: %f\n", longi);
      return 2;
    }

    printf("{latitude: %f, longitude: %f, info: '%s'}", lati, longi, info);
  }

  puts("\n]");
  return 0;
}
