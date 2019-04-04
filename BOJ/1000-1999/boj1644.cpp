#include <cstdio>
#include <vector>
using namespace std;

bool noPrime[4000001] = {true, true};
vector <int> prime;

int main(int argc, char *argv[]) {
  int n, i, j, cnt = 0;
  scanf("%d", &n);

  for (i = 4; i <= n; i += 2) noPrime[i] = true;
  for (i = 3; i * i <= n; i += 2) {
    if (!noPrime[i]) {
      for (j = i; i * j <= n; ++j) 
        noPrime[i * j] = true;
    }
  }
  prime.push_back(2);
  for (i = 3; i <= n; i += 2) if (!noPrime[i]) prime.push_back(i);

  int l = 0, r = 0, s = 2;
  while (r < prime.size() && l <= r) {
    if (s == n) {
      ++cnt; ++r;
      if (r < prime.size()) s += prime[r];
    }
    else if (s > n) s -= prime[l++];
    else {
      ++r;
      if (r < prime.size()) s += prime[r];
    }
  }
  return !printf("%d\n", cnt);
}