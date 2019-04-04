#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
  bool a[21] = {false, };
  int x, m;
  char cmd[10];

  scanf("%d", &m);
  while (m--) {
    scanf("%s", cmd);
    if (!strcmp(cmd, "add")) {
      scanf("%d", &x);
      a[x] = true;
    } else if (!strcmp(cmd, "remove")) {
      scanf("%d", &x);
      a[x] = false;
    } else if (!strcmp(cmd, "check")) {
      scanf("%d", &x);
      printf("%d\n", a[x] ? 1 : 0);
    } else if (!strcmp(cmd, "toggle")) {
      scanf("%d", &x);
      a[x] = !a[x];
    } else if (!strcmp(cmd, "all")) {
      for (int i=1; i<=20; ++i) a[i] = true;
    } else if (!strcmp(cmd, "empty")) {
      for (int i=1; i<=20; ++i) a[i] = false;
    }
  }
  return 0;
}