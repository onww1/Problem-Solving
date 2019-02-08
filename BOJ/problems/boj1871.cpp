#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool isNice(char *board) {
  int front = 0, back = 0;
  for (int i = 0; i < 3; ++i) front = front * 26 + board[i] - 'A';
  for (int i = 4; i < 8; ++i) back = back * 10 + board[i] - '0';
  return abs(front - back) <= 100;
}

int main(int argc, char *argv[]) {
  int n;
  char board[9];
  scanf("%d", &n);
  while (n--) {
    scanf(" %s", board);
    printf("%s\n", isNice(board) ? "nice" : "not nice");
  }
  return 0;
}