/*
 *  SWEA 3131. 100만 이하의 모든 소수
 * 
 *  시간 복잡도 : O(NloglogN)
 *  공간 복잡도 : O(N)
 * 
 *  이미 너무나도 유명한 에라토스테네스의 체죠.
 *  먼저 2부터 시작해서 i * i가 100만과 작거나 같은 동안에만 첫 for문을 돕니다.
 *  그 때, 만난 수가 아직 prime이 아니라고 체크가 되지 않았으면 그 수는 소수이므로 
 *  그 수를 바로 출력해줍니다. 이후 j = i부터 시작해서 i * j가 100만보다 작거나 같은 수들은 
 *  모두 소수가 아니라고 체크해줍니다. j = i부터 시작한 이유는 그 이전 수는 이전 다른 수에 의해서 
 *  체크가 돼서 굳이 확인할 필요가 업기 때문입니다.
 * 
 *  이후 i * i가 100만을 넘어서면 그 이후부터는 순서대로 돌면서 noPrime 체크가 되지 않은 수만 
 *  다 출력해주도록 합니다.
 */

#include <cstdio>
using namespace std;
typedef long long ll;

bool noPrime[1000005]; // 소수가 아닌 수를 체크할 배열
int main(int argc, char *argv[]) {
  ll i, j;

  // i * i <= 1000000인 이유는 그보다 큰 수는 이미 다 체크가 되었기 때문입니다.
  for (i = 2; i * i <= 1000000; ++i) { 
    if (!noPrime[i]) {
      printf("%lld ", i);
      // i * i부터 체크가 되지 않았기 때문에 여기서부터 모두 체크해줍니다.
      for (j = i; i * j <= 1000000; ++j) 
        noPrime[i * j] = true;
    }
  }

  // 나머지 소수들을 모두 출력합니다.
  for (; i <= 1000000; ++i)
    if (!noPrime[i]) printf("%lld ", i);
  return !printf("\n"); 
}