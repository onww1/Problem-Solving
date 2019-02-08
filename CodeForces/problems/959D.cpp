#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e5;

set <int> used_prime;
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

int a, ans[MAX], used[MAX + 1];
int main(int argc, char *argv[]) {
  int n, i, j, flg = 1, p = 0;
  init();
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (!flg) {
      while (used_prime.find(prime[p]) != used_prime.end()) ++p;
      ans[i] = prime[p];
      used_prime.insert(prime[p]);
    } else {
      vector <int> factor;
      int tmp = a;
      for (j = 0; (long long)prime[j] * prime[j] <= tmp;) {
        if (tmp % prime[j]) ++j;
        else {
          if (used_prime.find(prime[j]) != used_prime.end()) {
            flg = 0;
            break;
          }
          factor.push_back(prime[j]);
          while (tmp % prime[j] == 0) tmp /= prime[j];
        }
      }
      if (tmp > 1) factor.push_back(tmp);
      if (flg) {
        for (int fac : factor) used_prime.insert(fac);
        ans[i] = a;
        used[a] = 1;
      } else {
        for (int k = a + 1; true; ++k) {
          bool valid = true;
          for (int fac : used_prime) {
            if (k % fac == 0) {
              valid = false;
              break;
            }
          }
          if (!valid) continue;

          ans[i] = k; used[k] = 1;
          for (j = 0; (long long)prime[j] * prime[j] <= k;) {
            if (k % prime[j]) ++j;
            else {
              used_prime.insert(prime[j]);
              while (k % prime[j] == 0) k /= prime[j];
            }
          }
          if (k > 1) used_prime.insert(k);
          break;
        }
      }
    }
  }
  for (i = 0; i < n; ++i) printf("%d ", ans[i]);
  return !printf("\n");
}