/*
 *  factorization
 */

#include <iostream>
using namespace std;

const int MOD = 1'000'000'000;
int cnt[10001];

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int N, K;
  cin >> N >> K;

  int temp = N;
  N = N + --K;
  K = N - K < K ? N - K : K;

  for (int i = 0; i < K; ++i) {
    int n = N - i, mod = 2;
    while (mod * mod <= N - i && n > 1) {
      while (n % mod == 0) {
        n /= mod;
        ++cnt[mod];
      }
      ++mod;
    }
    if (n > 1) ++cnt[n];

    n = i + 1, mod = 2;
    while (mod * mod <= i + 1 && n > 1) {
      while (n % mod == 0) {
        n /= mod;
        --cnt[mod];
      }
      ++mod;
    }
    if (n > 1) --cnt[n];
  }
  
  long long res = 1;
  for (int i = 2; i <= N; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      res = (res * i) % MOD;
    }
  }

  cout << res << '\n';
  return 0;
}

/*
 * Dynamic Programming
 */

// #include <iostream>
// #define MOD 1000000000
// using namespace std;

// int main(int argc, char *argv[]) {
//   cin.tie(0);
//   ios_base::sync_with_stdio(false);

//   int N, K;
//   cin >> N >> K;

//   int DP[5001][5001] = {0, };
//   for (int i=0; i<=N; ++i) DP[i][1] = 1;
//   for (int j=1; j<=K; ++j) DP[0][j] = 1;

//   for (int j=2; j<=K; ++j) {
//     for (int i=1; i<=N; ++i) {
//       DP[i][j] = (DP[i-1][j] + DP[i][j-1])%MOD;
//     }
//   }
//   cout << DP[N][K] << '\n';

//   return 0;
// }
