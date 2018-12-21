#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T, N, M, K, S, u, v;
  bool map[1001][1001];
  vector<int> dst;

  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> N >> M >> K >> S;
    memset(map, false, 1001 * (N+1));
    dst.clear();

    for (int i = 0; i < K; ++i) {
      cin >> u;
      dst.push_back(u);
    }

    for (int i = 0; i < M; ++i) {
      cin >> u >> v;
      map[u][v] = map[v][u] = true;
    }

    
  }
}