#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  bool noPrime[1000001] = { true, true, };
  for (int i=2; i*i<=1000000; ++i) {
    if (!noPrime[i]) {
      for (int j=i; i*j<=1000000; ++j) {
        noPrime[i*j] = true;
      }
    }
  }

  vector<int> prime;
  for (int i=3; i<1000000; ++i) 
    if (!noPrime[i]) prime.push_back(i);
  
  int even;
  while (1) {
    scanf("%d", &even);
    if (!even) break;

    int idx = 0;
    for (; idx < prime.size() && prime[idx] < even; ++idx) {
      if (!noPrime[even - prime[idx]]) {
        printf("%d = %d + %d\n", even, prime[idx], even - prime[idx]);
        break;
      }
    }
    if (idx == prime.size() || prime[idx] >= even) {
      printf("Goldbach's conjecture is wrong.\n");
    }
  }
  return 0;
}