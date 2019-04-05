#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[6], tmp[6], n, noPrime[30001] = {1, 1, };
vector <int> prime;

bool isPrime(int num) {
  for (int i = 0; prime[i] * prime[i] <= num; ++i) {
    if (num % prime[i] == 0) return false;
  }
  return true;
}

void check(int visited, int &mn, int &mx) {
  if (visited == (1 << (n-1)) - 1) {
    if (tmp[0] < 2 || !isPrime(tmp[0])) return;
    mn = min(mn, tmp[0]);
    mx = max(mx, tmp[0]);
    return;
  }

  for (int i = 0; i < n - 1; ++i) {
    if (visited & (1 << i)) continue;
    int org[2] = {tmp[i], tmp[i+1]};

    tmp[i] = tmp[i+1] = org[0] + org[1];
    for (int j = i-1; j >= 0; --j) if (visited & (1 << j)) tmp[j] = tmp[i]; else break;
    for (int j = i+1; j < n - 1; ++j) if (visited & (1 << j)) tmp[j + 1] = tmp[i]; else break;
    check(visited | (1 << i), mn, mx);

    tmp[i] = tmp[i+1] = org[0] - org[1];
    for (int j = i-1; j >= 0; --j) if (visited & (1 << j)) tmp[j] = tmp[i]; else break;
    for (int j = i+1; j < n - 1; ++j) if (visited & (1 << j)) tmp[j + 1] = tmp[i]; else break;
    check(visited | (1 << i), mn, mx);

    tmp[i] = tmp[i+1] = org[0] * org[1];
    for (int j = i-1; j >= 0; --j) if (visited & (1 << j)) tmp[j] = tmp[i]; else break;
    for (int j = i+1; j < n - 1; ++j) if (visited & (1 << j)) tmp[j + 1] = tmp[i]; else break;
    check(visited | (1 << i), mn, mx);

    if (org[1] != 0) {
      tmp[i] = tmp[i+1] = org[0] / org[1];
      for (int j = i-1; j >= 0; --j) if (visited & (1 << j)) tmp[j] = tmp[i]; else break;
      for (int j = i+1; j < n - 1; ++j) if (visited & (1 << j)) tmp[j + 1] = tmp[i]; else break;
      check(visited | (1 << i), mn, mx);
    }
    
    tmp[i] = org[0], tmp[i+1] = org[1];
    for (int j = i-1; j >= 0; --j) if (visited & (1 << j)) tmp[j] = org[0]; else break;
    for (int j = i+1; j < n - 1; ++j) if (visited & (1 << j)) tmp[j + 1] = org[1]; else break;
  }
}

int main(int argc, char *argv[]) {
  int i, j;
  for (i = 2; i <= 30000; ++i)
    if (!noPrime[i]) {
      prime.push_back(i);
      for (j = i * i; j <= 30000; j += i) 
        noPrime[j] = 1;
    }

  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);
  int mn = 1e9, mx = 0;
  do {
    memcpy(tmp, a, sizeof(a));
    check(0, mn, mx);
  } while (next_permutation(a, a + n));
  if (!mx) return !printf("-1\n");
  return !printf("%d\n%d\n", mn, mx);
}