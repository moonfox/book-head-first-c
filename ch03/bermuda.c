#include <stdio.h>

int main(int argc, char const *argv[])
{
  char info[80];
  float lati;
  float longi;

  while (scanf("%f,%f,%79[^\n]", &lati, &longi, info) == 3)
  {

    if ((lati > 26.0) && (lati < 34.0))
      if ((longi > -76.0) && (longi < -64.0))
        printf("%f,%f,%s\n", lati, longi, info);
  }

  return 0;
}
