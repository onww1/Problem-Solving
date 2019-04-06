#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char pre[27], in[27], order[27];

void postorder(int s, int e) {
  if (s > e) return;
  if (s == e) {
    printf("%c", pre[s]);
    return;
  }

  for (int i = s + 1; i <= e; ++i) {
    if (order[pre[s] - 'A'] < order[pre[i] - 'A']) {
      postorder(s + 1, i - 1);
      postorder(i, e);
      printf("%c", pre[s]);
      break;
    }
    else if (i == e) {
      postorder(s + 1, e);
      printf("%c", pre[s]);
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  while (~scanf(" %s %s", pre, in)) {
    int len = strlen(pre);
    for (int i = 0; in[i]; ++i) order[in[i] - 'A'] = i;
    postorder(0, len - 1);
    puts("");
  }
  return 0;
}