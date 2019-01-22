#include <cstdio>
#include <cstring>
using namespace std;

char in[105];
int main(int argc, char *argv[]) {
  int n, len, i, j;
  scanf("%d", &n);
  while (~scanf(" %s", in)) {
    len = strlen(in);
    for (i = 0, j = 0; i < len - 1; i += 2, ++j) 
      in[j] = (in[i] + in[i + 1] - n - 2 * 'a' + 26) % 26 + 'a';
    in[j] = 0;
    printf("%s ", in);
  }
  return 0;
}