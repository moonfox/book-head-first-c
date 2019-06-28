#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  char *delivery = "";
  char ch;
  int thick = 0;

  // d: 表示选项后面必须要有参数
  while ((ch = getopt(argc, argv, "d:t")) != EOF)
  {
    switch (ch)
    {
    case 'd':
      delivery = optarg;
      break;
    case 't':
      thick = 1;
      break;
    default:
      // 如果d后面为空，或出现了非-d/-t的参数，则引发错误
      fprintf(stderr, "Unkown option: %s\n", optarg);
      return 1;
      break;
    }
  }

  //  使`argv`指向选项后的第一个参数
  argc -= optind;
  argv += optind;

  if (thick)
  {
    puts("Thick cruts.");
  }

  if (delivery[0])
  {
    printf("To be delivered %s\n", delivery);
  }

  puts("Ingredients:");

  // argv[0]此时指向选项后的第一个参数 Anchovice Pineapple
  // ./order_pizza -d now -t Anchovice Pineapple
  for (int i = 0; i < argc; i++)
  {
    puts(argv[i]);
  }

  return 0;
}
