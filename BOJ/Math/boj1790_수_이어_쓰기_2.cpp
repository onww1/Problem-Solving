/*
 *  BOJ 1790. 수 이어 쓰기 2
 *  
 *  각 자릿수마다 가장 끝수까지 했을 때 몇 개의 숫자가 있는지를 cnt 배열에 저장했습니다.
 *  그렇게 하고, 우선적으로 이 k에 해당하는 값이 존재하는지를 확인했습니다.
 *  그 자릿수에서 나올 수 있는 숫자의 최대 갯수에서 현재 들어온 n값보다 큰 수들에 대한 갯수를 빼줬을 때, 
 *  k가 이것보다 크다면 나올 수 없는 수입니다. 이때 9에 대한 수의 갯수는 int형 범위를 넘어가서 따로 처리했습니다.
 *  그 다음은 k번째 자리수를 가지고 있는 수가 몇 자리수인지를 반복문을 돌려서 찾았고,
 *  그것을 기반으로 그 수를 찾았습니다. (target이 해당 수)
 *  그리고 그것을 이용해서 k번째 수를 뽑아냈습니다.
 */

#include <cstdio>
using namespace std;

// 자릿 수를 반환하는 함수
int cipher(int number) { 
  int count = 0;
  while (number) ++count, number /= 10;
  return count;
}

// 분할정복을 통해서 지수 계산을 해주는 함수
int pow(int base, int exp) {
  int ret = 1;
  while (exp) {
    if (exp % 2) ret *= base;
    base *= base;
    exp /= 2;
  }
  return ret;
}

// cnt 함수를 채워주는 함수
void init(int *cnt) {
  for (int i = 1, j = 9; i < 9; ++i, j *= 10) 
    cnt[i] = cnt[i-1] + i * j;
  cnt[9] = cnt[8] + 9;
}

int main(int argc, char *argv[]) {
  int n, k, i, l, cnt[10] = {0};
  scanf("%d %d", &n, &k);
  init(cnt);
  l = cipher(n);

  // k가 가능한 값인지 확인
  if ((l == 9 && k > cnt[9]) || (k > cnt[l] - (pow(10, l) - n - 1) * l)) 
    return !printf("-1\n");
  
  // k번째 수를 가지고 있는 수가 몇 자리 수인지 찾는 과정
  for (i = 1; i < 9 && k > cnt[i]; ++i);

  // 위에서 얻은 값을 통해서 k번째 자리 값을 가지고 있는 수를 찾음
  int target = pow(10, i-1) + (k - cnt[i-1] - 1) / i;

  // k번째 수를 뽑아서 출력
  return !printf("%d\n", target / pow(10, i - (k - cnt[i-1] - 1) % i - 1) % 10);
}