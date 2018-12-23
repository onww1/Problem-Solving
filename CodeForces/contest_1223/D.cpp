#include <iostream>
#include <vector>
using namespace std;

int N, S, u, v;
vector< vector<int> > edges;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> S;
  edges.resize(N+1);
  for (int i=0; i<N-1; ++i) {
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int cnt = 0;
  for (int i=1; i<=N; ++i) {
    if (edges[i].size() == 1) ++cnt;
  }

  cout << fixed;
  cout.precision(6);
  cout << ((double)(2 * S) / (double)cnt) << '\n';

  return 0;
}