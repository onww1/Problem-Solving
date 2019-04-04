#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Node {
  int v, d;
};

int T, N, a, b, c;
vector< vector<Node> > map;
vector<bool> visited;

int solve(int node, ll &cnt);
ll get_abs(ll a);
ll get_max(ll a, ll b);

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> T;
  for (int test_case = 1; test_case <= T; ++test_case) {
    cin >> N;
    map.clear();
    map.resize(2 * N + 1);
    visited.clear();
    visited.resize(2 * N + 1, false);

    for (int i = 0; i < 2 * N - 1; ++i) {
      cin >> a >> b >> c;
      map[a].push_back({b, c});
      map[b].push_back({a, c});
    }

    ll answer = 0;
    visited[2*N] = true;
    solve(map[2*N][0].v, answer);
    cout << '#' << test_case << ' ' << answer << '\n';
  }

  return 0;
}

int solve(int node, ll &cnt) {
  if (node <= N) 
    return map[node][0].d;
  visited[node] = true;

  vector<Node>& vec = map[node];
  int val[2], idx = 0, retLoad;
  for (int i=0; i<3; ++i) {
    if (visited[vec[i].v]) {
      retLoad = vec[i].d;
    } else {
      val[idx++] = solve(vec[i].v, cnt);
    }
  }

  cnt += get_abs(val[0] - val[1]);
  visited[node] = false;
  return get_max(val[0], val[1]) + retLoad;
}

ll get_max(ll a, ll b) {
  return a > b ? a : b;
}

ll get_abs(ll a) {
  return a > 0 ? a : -a;
}