#include <cstdio>
#include <cstring>
using namespace std;

char in1[101], in2[101], res[101];
int main(int argc, char *argv[]) {
  int l1, l2, len = 0;
  scanf("%s %s", in1, in2);
  l1 = strlen(in1);
  l2 = strlen(in2);
  while (l1 > 0 && l2 > 0) {
    res[len] += in1[l1 - 1] + in2[l2 - 1] - '0';
    if (res[len] > '1') res[len + 1] += 1, res[len] -= 2;
    ++len, --l1, --l2;
  }
  while (l1 > 0) {
    res[len] += in1[l1 - 1];
    if (res[len] > '1') res[len + 1] += 1, res[len] -= 2;
    ++len, --l1;
  }
  while (l2 > 0) {
    res[len] += in2[l2 - 1];
    if (res[len] > '1') res[len + 1] += 1, res[len] -= 2;
    ++len, --l2;
  }
  res[len] += '0';

  bool flag = false;
  for (int i = len; i >= 0; --i) {
    if (res[i] == '1') flag = true, printf("1");
    else if (flag && res[i] == '0') printf("0");
  }
  if (!flag) printf("0");
  return !printf("\n");
}