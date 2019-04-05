/*
 *  BOJ 3005. 크로스워드 퍼즐 쳐다보기
 * 
 *  처음부터 끝까지 순회하면서 이게 단어의 첫 글자인지 확인하고,
 *  첫 글자라면 그것을 word 배열에 넣고, 현재 저장되어 있는 단어랑 비교해서 
 *  사전순으로 더 앞서는 단어라면 바꿔서 집어 넣는 논리입니다.
 */

#include <cstdio>
#include <cstring>
using namespace std;

char word[25], ans[25], board[20][21];
int main(int argc, char *argv[]) {
  int R, C, i, j, k;
  scanf("%d %d", &R, &C);
  for (i = 0; i < R; ++i) scanf(" %s", board[i]);
  for (i = 0; i < R; ++i) {
    for (j = 0; j < C; ++j) {
      // 가로로 되어 있는 단어를 확인하는 로직
      if (!j || board[i][j-1] == '#') {
        // word 배열에 단어를 집어 넣는다.
        for (k = j; k < C && board[i][k] != '#'; ++k) word[k-j] = board[i][k];
        word[k-j] = 0;
        // 비교를 해서 방금 찾은 단어가 더 앞서면 ans에 집어넣어 준다.
        if (k - j > 1 && (ans[0] == 0 || strcmp(ans, word) > 0)) strcpy(ans, word);
      }

      // 세로로 되어 있는 단어를 확인하는 로직
      if (!i || board[i-1][j] == '#') {
        // word 배열에 단어를 집어 넣는다.
        for (k = i; k < R && board[k][j] != '#'; ++k) word[k-i] = board[k][j];
        word[k-i] = 0;
        // 비교를 해서 방금 찾은 단어가 더 앞서면 ans에 집어넣어 준다.
        if (k - i > 1 && (ans[0] == 0 || strcmp(ans, word) > 0)) strcpy(ans, word);
      }
    }
  }
  return !printf("%s\n", ans);
}