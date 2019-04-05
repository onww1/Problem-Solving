#include <iostream>
#include <vector>
#define MOD 1'000'000'000
using namespace std;

vector< vector<int> > combi;
int combination(int n, int k) {
  int &ret = combi[n][k];
  if (ret != -1) return ret;
  ret = (combination(n-1, k-1) + combination(n-1, k)) % MOD;
  return ret;
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  N += --K;
  if (N - K < K) K = N - K;
  combi.resize(N+1, vector<int>(K+1, -1));

  for (int i=0; i<=N; ++i) combi[i][0] = 1;
  for (int i=0; i<=K; ++i) combi[i][i] = 1;
  cout << combination(N, K) << '\n';

  return 0;
}
