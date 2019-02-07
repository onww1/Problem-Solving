#include <cstdio>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
const int MAX = 3e5;

pii books[MAX];
int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &books[i].X);
    books[i].Y = i + 1;
  }
  sort(books, books + n);
  for (i = n-1; i > 0; --i) {
    if (books[i].Y < books[i-1].Y) 
      return !printf("%d\n", i);
  }
  return !printf("0\n");
}