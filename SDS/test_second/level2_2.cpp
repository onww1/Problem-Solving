#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

struct point {
  int v, dist;
};

int tsp(int cur, int visited, vector< vector<int> >& dist);
int get_min(int a, int b) { return a < b ? a : b; }

int T, N, M, K, S, u, v;
int cache[11][1025];
vector< vector<int> > map;

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> N >> M >> K >> S;
    map.clear();
    map.resize(N+1);

    vector<bool> isDst(N+1, false);
    vector<int> dst;
    isDst[S] = true;
    dst.push_back(S);
    for (int i = 0; i < K; ++i) {
      cin >> u;
      isDst[u] = true;
      dst.push_back(u);
    }
    sort(dst.begin(), dst.end());
    vector< vector<int> > edges(K+1, vector<int>(K+1));

    for (int i = 0; i < M; ++i) {
      cin >> u >> v;
      map[u].push_back(v);
      map[v].push_back(u);
    }

    for (int i = 0; i < dst.size(); ++i) {
      queue<point> q;
      vector<bool> visited(N+1);
      q.push({dst[i], 0});
      visited[dst[i]] = true;

      while (!q.empty()) {
        int v = q.front().v;
        int d = q.front().dist;
        q.pop();

        if (isDst[v]) {
          int left = -1, right = dst.size(), mid;
          while (left + 1 < right) {
            mid = (left + right) / 2;
            if (dst[mid] == v) break;
            else if (dst[mid] < v) left = mid;
            else right = mid;
          }
          edges[i][mid] = d;
        }

        for (auto &it : map[v]) {
          if (!visited[it]) {
            visited[it] = true;
            q.push({it, d + 1});
          }
        }
      }
    }

    // for (auto &it : edges) {
    //   for (auto &it2 : it) {
    //     cout << it2 << '\t';
    //   }
    //   cout << '\n';
    // }

    memset(cache, 0, sizeof(int) * 11 * 1025);
    cout << '#' << test_case << ' ' << tsp(0, 1, edges) << '\n';
  }

  return 0;
}

int tsp(int cur, int visited, vector< vector<int> >& dist) {
  if (visited == (1 << dist.size()) - 1) return  dist[cur][0];

  int& ret = cache[cur][visited];
  if (ret != 0) return ret;
  ret = INF;
  for (int next = 0; next < dist.size(); ++next) {
    if (visited & (1 << next)) continue;
    if (dist[cur][next] == 0) continue;
    ret = get_min(ret, tsp(next, visited | (1 << next), dist) + dist[cur][next]);
  }
  return ret;
}