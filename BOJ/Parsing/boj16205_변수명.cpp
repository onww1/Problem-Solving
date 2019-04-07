#include <cstdio>
#include <cstring>
using namespace std;

bool isUpperCase(char c) { return 'A' <= c && c <= 'Z'; }
char toUpper(char c) { return isUpperCase(c) ? c : c - 'a' + 'A'; }
char toLower(char c) { return isUpperCase(c) ? c - 'A' + 'a' : c; }

char in[105], res[3][200];
int main(int argc, char *argv[]) {
  int n, len, i, a, b, c;
  scanf("%d %s", &n, in);
  len = strlen(in);
  res[0][0] = res[1][0] = toLower(in[0]);
  res[2][0] = toUpper(in[0]);
  
  bool first = false;
  for (i = a = b = c = 1; i < len; ++i) {
    if (in[i] == '_') {
      first = true;
    } else if (isUpperCase(in[i])) {
      res[0][a++] = res[2][c++] = in[i];
      res[1][b++] = '_'; res[1][b++] = toLower(in[i]);
    } else {
      if (first) {
        res[0][a++] = res[2][c++] = toUpper(in[i]);
        res[1][b++] = '_'; res[1][b++] = in[i];
        first = false;
      } else {
        res[0][a++] = res[1][b++] = res[2][c++] = in[i];
      }
    }
  }
  res[0][a] = res[1][b] = res[2][c] = 0;
  for (i = 0; i < 3; ++i) printf("%s\n", res[i]);
  return 0;
}