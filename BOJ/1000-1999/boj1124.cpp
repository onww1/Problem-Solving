/*
 *  BOJ 1124. 언더프라임
 *  
 *  - naive 버전 (아래 코드)
 *  시간 복잡도 : O(NloglogN + Nsqrt(N/logN))
 *  공간 복잡도 : O(N)
 * 
 *  - 에라토스테네스의 체 변형 버전 (위 코드)
 *  시간 복잡도 : O(NloglogN)
 *  공간 복잡도 : O(N) 
 * 
 *  naive 버전의 경우, 에라토스테네스의 체로 10만까지의 소수를 모두 구하고,
 *  a부터 b까지 돌면서 소수를 이용하여 소인수분해를 했습니다. 그렇게 해서 소인수의 갯수를 
 *  에라토스테네스의 체에서 사용했던 배열에 접근해서 소수인지 확인하고 카운트했습니다. 
 * 
 *  에라토스테네스의 체 변형 버전의 경우, 에라토스테네스의 체처럼 하는데 
 *  배열에 이게 소수인지 아닌지를 넣는게 아니고, 소인수의 갯수를 저장하는 것입니다.
 *  소수인 수들은 이전에 추가된 것이 없으므로 접근했을 때 값이 0입니다. 
 *  따라서 이것을 기준으로 그 수에서 시작해서 그 수로 표현할 수 있는 모든 수에 
 *  소인수의 수를 더해주는 것입니다. 이때 거듭제곱 형태까지도 모두 커버해줍니다. 
 *  그렇게 10만까지 모든 수의 소인수의 갯수를 미리 구해놨으므로 각 수마다  
 *  언더프라임인지는 O(1)에 알 수 있습니다. 따라서 마지막에 O(n)에 구합니다.
 */

#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 100000;
int factor[MAX + 1];

// 에라토스테네스의 체를 변형하여 소인수의 갯수를 구해주는 함수.
void init() {
  for (ll i = 2; i <= MAX; ++i)
    if (factor[i] == 0) 
      for (ll j = i; j <= MAX; j *= i)
        for (ll k = j; k <= MAX; k += j) 
          ++factor[k];
}

int main(int argc, char *argv[]) {
  int a, b, i, cnt = 0;
  init();
  scanf("%d %d", &a, &b);
  for (i = a; i <= b; ++i) 
    if (factor[factor[i]] == 1) ++cnt;
  return !printf("%d\n", cnt);
}


// #include <cstdio>
// #include <vector>
// using namespace std;
// typedef long long ll;

// const int MAX = 100000;
// bool noPrime[MAX + 1] = {true, true, };
// vector <int> prime;

// // 모든 소수를 구해서 prime vector에 넣어줌.
// void init() {
//   for (int i = 2; i <= MAX; ++i) {
//     if (!noPrime[i]) {
//       prime.push_back(i);
//       for (int j = i; (ll)i * j <= MAX; ++j) 
//         noPrime[i * j] = true;
//     }
//   }
// }

// // n이 언더프라임인지 알려줌.
// bool isUnderPrime(int n) {
//   int cnt = 0, i;
//   for (i = 0; prime[i] * prime[i] <= n;) {
//     if (n % prime[i]) ++i;
//     else ++cnt, n /= prime[i];
//   }
//   if (n > 1) ++cnt;
//   return !noPrime[cnt];
// }

// int main(int argc, char *argv[]) {
//   int a, b, i, cnt = 0;
//   init();
//   scanf("%d %d", &a, &b);
//   for (i = a; i <= b; ++i) 
//     if (isUnderPrime(i)) ++cnt;
//   return !printf("%d\n", cnt);
// }
