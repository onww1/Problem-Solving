#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e5;

set <int> used;
vector <int> prime;
bool noPrime[4000001];

void init() {
  for (int i = 2; i <= 4000000; ++i) {
    if (!noPrime[i]) {
      prime.push_back(i);
      for (long long j = (long long)i * i; j <= 4000000LL; j += i) 
        noPrime[j] = true;
    }
  }
}

void get_factor(int n, vector <int> &vec) {
  for (int i = 0; (long long)prime[i] * prime[i] <= n; ++i) {
    if (n % prime[i] == 0) {
      if (used.find(prime[i]) != used.end()) {
        vec.clear(); 
        vec.push_back(-1);
        return;
      }
      vec.push_back(prime[i]);
      while (n % prime[i] == 0) n /= prime[i];
    }
  }
  if (n > 1) {
    if (used.find(n) != used.end()) {
      vec.clear(); vec.push_back(-1);
      return;
    }
    vec.push_back(n);
  }
}

int a, ans[MAX];
int main(int argc, char *argv[]) {
  int n, i, j, flg = 1, p = 0;
  init();
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (!flg) {
      while (used.find(prime[p]) != used.end()) ++p;
      ans[i] = prime[p];
      used.insert(prime[p]);
    } else {
      vector <int> factor;
      get_factor(a, factor);
      if (factor[0] > 0) {
        for (int fac : factor) used.insert(fac);
        used.insert(a);
        ans[i] = a;
      } else {
        int k; flg = 0;
        for (k = a + 1; true; ++k) {
          bool valid = true;
          for (int fac : used)
            if (k % fac == 0) {
              valid = false;
              break;
            }
          if (valid) break;
        }
        ans[i] = k;
        get_factor(k, factor);
        for (int fac : factor) used.insert(fac);
        used.insert(k);
      }
    }
  }
  for (i = 0; i < n; ++i) printf("%d ", ans[i]);
  return !printf("\n");
}