#include <stdio.h>
#include <string.h>

void find_track(char search_for[]);
char tracks[][80] = {
    "I left my heart in Harvard Med School",
    "Newark, Newark",
    "Dancing withc a Dark",
    "From here to maternity",
    "The girl from Iwo Jima"};

int main(int argc, char const *argv[])
{
  char search_for[80];
  printf("search for: ");

  // 从标准输入中录入的字符串，末尾自动追回一个'\n'(换行符)
  fgets(search_for, 80, stdin);

  int len = strlen(search_for);

  // 把末尾的'\n'替换为字符串结束符'\0'
  search_for[len - 1] = '\0';

  // 如录入字符为'hello world'，实际search_for获得的为'hello world\n\0'，一共13个字符
  // 此时search_for保存的内容为'hello world0\0'
  // strlen计算字符串长度时，不把'\0'计算在长度内，它遇到第一个'\0'时，停止查找
  // 所以strlen计算的结果为11个字符

  printf("input is '%s', len is %d\n", search_for, strlen(search_for));

  find_track(search_for);
  return 0;
}

void find_track(char search_for[])
{
  for (int i = 0; i < 5; i++)
  {
    if (strstr(tracks[i], search_for))
      printf("Track %i: '%s'\n", i, tracks[i]);
  }
}