#include <cstdio>
#include <vector>
using namespace std;

char buf[1 << 17];
inline char read() {
  static int idx = 1 << 17;
  if (idx == 1 << 17) {
    int nidx = fread(buf, 1, 1 << 17, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}
inline int readInt() {
  int sum = 0;
  char now = read();
  while (now == ' ' || now == '\n') now = read();
  while ('0' <= now && now <= '9') {
    sum = sum * 10 + now - '0';
    now = read();
  }
  return sum;
}

// bool map[405][405];
// int main(int argc, char *argv[]) {
//   int N, K, u, v, i, j, k;
//   N = readInt();
//   K = readInt();
//   for (i = 0; i < K; ++i) {
//     u = readInt();
//     v = readInt();
//     map[u][v] = true;
//   }
//   for (k = 1; k <= N; ++k) {
//     for (i = 1; i <= N; ++i) {
//       for (j = 1; j <= N; ++j) {
//         map[i][j] = map[i][j] || (map[i][k] && map[k][j]);
//       }
//     }
//   }

//   N = readInt();
//   for (i = 0; i < N; ++i) {
//     u = readInt();
//     v = readInt();
//     if (!map[u][v] && !map[v][u]) printf("0\n");
//     else if (map[u][v]) printf("-1\n");
//     else printf("1\n");
//   }
//   return 0;
// }

bool isPossible[405][405];
vector <int> edges[405];

void solve(int s, int e) {
  isPossible[s][e] = true;
  for (auto it : edges[e]) {
    if (!isPossible[s][it])
      solve(s, it);
  }
}

int main(int argc, char *argv[]) {
  int n, k, u, v, i;
  n = readInt();
  k = readInt();

  for (i = 0; i < k; ++i) {
    u = readInt();
    v = readInt();
    edges[u].push_back(v);
  }

  for (i = 1; i <= n; ++i) solve(i, i);

  n = readInt();
  for (i = 0; i < n; ++i) {
    u = readInt();
    v = readInt();
    if (isPossible[u][v]) printf("-1\n");
    else if (isPossible[v][u]) printf("1\n");
    else printf("0\n");
  }
  return 0;
}