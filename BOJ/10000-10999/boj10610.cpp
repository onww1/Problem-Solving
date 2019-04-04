#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
  char input[100001];
  int count[10] = {0, };
  scanf("%s", input);
  int len = strlen(input);
  for (int i=0; i<len; ++i) {
    ++count[input[i] - '0'];
  }

  if (!count[0]) {
    printf("-1\n");
    return 0;
  }

  int sum = 0;
  for (int i=1; i<10; ++i) 
    sum += (i * count[i]);
  
  if (sum % 3) {
    printf("-1\n");
    return 0;
  }
  
  int idx = 9;
  for (int i=0; i<len; ++i) {
    if (count[idx]) {
      --count[idx];
      input[i] = idx + '0';
    } else {
      --idx;
      --i;
    }
  }
  printf("%s\n", input);
  return 0;
}