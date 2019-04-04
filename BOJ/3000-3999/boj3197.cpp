/*
 *  BOJ 3197. 백조의 호수 
 *
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N^2) 
 *
 *  한 백조에서 다른 백조로 갈 수 있는지를 그 때마다 새롭게 BFS를 하면 시간초과가 납니다. 
 *  그래서 저는 전체 빙판이 녹는 것을 확인하는 BFS에 대한 Queue를 2개 두고,
 *  또한 백조가 만날 수 있는지 확인하는 BFS에 대한 Queue를 또 따로 2개를 둬서, 
 *  빙판을 만났을 때는 다른 큐에 넣어두고, 빙판이 아닌 곳에 대해서는 현재 큐에 담아서 
 *  탐색을 하는 식으로 진행을 했습니다. 
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1500;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};

int R, C;
int MAP[MAX + 1][MAX + 1];
char in[MAX + 1];
bool main_visited[MAX + 1][MAX + 1], check_visited[MAX + 1][MAX + 1];
pii src = {-1, -1}, dst;
queue <pii> Q[2], L[2], rm;

// 현재 상황에서 한 백조를 기준으로 다른 백조를 만날 수 있는지 확인하는 함수
bool check(int T) {
  // T가 하나씩 증가하므로 현재 가르키는 큐를 계속 바꿀 수 있습니다.
  while (!L[T % 2].empty()) {
    int r = L[T % 2].front().X;
    int c = L[T % 2].front().Y;
    L[T % 2].pop();

    // 다른 백조를 만나면 true를 리턴
    if (r == dst.X && c == dst.Y) return true;

    for (int k = 0; k < 4; ++k) {
      int dr = r + move_r[k];
      int dc = c + move_c[k];
      if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
      if (!check_visited[dr][dc]) {
        check_visited[dr][dc] = true;
        // 이동할 수 없는 공간이라면 다른 큐에 넣는다.
        if (!MAP[dr][dc]) L[1 - T % 2].push({dr, dc});
        // 이동할 수 있는 공간이라면 현재 큐에 넣는다.
        else L[T % 2].push({dr, dc});
      }
    }
  }

  // 현재 큐를 탐색했는데도 다른 백조를 만나지 못했으면 false를 리턴.
  return false;
}

int main(int argc, char *argv[]) {
  scanf("%d %d", &R, &C);
  for (int i = 0; i < R; ++i) {
    scanf(" %s", in);
    for (int j = 0; in[j]; ++j) {
      // 갈 수 없는 곳은 0으로 처리
      if (in[j] == 'X') MAP[i][j] = 0;
      else {
        // 백조 자리이면 백조의 위치를 따로 저장하고 1로 저장한다.
        if (in[j] == 'L') {
          if (src == pii(-1, -1)) {
            src = {i, j};
            L[0].push(src);
            check_visited[i][j] = true;
          }
          else dst = {i, j};
        }
        MAP[i][j] = 1;
        Q[0].push({i, j});
        main_visited[i][j] = true;
      }
    }
  }

  int T = 0;  // T는 시간을 가르키는 변수
  while (true) {
    // 현재 상황에서 백조가 만날 수 있으면 T를 출력한다.
    if (check(T)) return !printf("%d\n", T);

    // 현재 상태에서 녹는 빙하를 다 체크.
    while (!Q[T % 2].empty()) {
      int r = Q[T % 2].front().X;
      int c = Q[T % 2].front().Y;
      Q[T % 2].pop();
      for (int k = 0; k < 4; ++k) {
        int dr = r + move_r[k];
        int dc = c + move_c[k];
        if (dr < 0 || dr >= R || dc < 0 || dc >= C) continue;
        if (!main_visited[dr][dc]) {
          main_visited[dr][dc] = true;
          if (MAP[dr][dc]) Q[T % 2].push({dr, dc});
          else {
            Q[1 - T % 2].push({dr, dc});
            rm.push({dr, dc});
          }
        }
      }
    }

    // 체크된 빙하를 다 갈 수 있는 공간으로 바꿔준다.
    while (!rm.empty()) {
      MAP[rm.front().X][rm.front().Y] = 1;
      rm.pop();
    }

    // 하나의 루틴이 끝났으면 T를 증가시킨다.
    T++;
  }

  return 0;
}