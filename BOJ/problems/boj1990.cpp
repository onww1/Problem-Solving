/*
 *  BOJ 1990. 소수인팰린드롬
 *  
 *  시간 복잡도 : O(sqrt N * loglogN + 10^(logN / 2) * sqrt(logN) )
 *  공간 복잡도 : O(sqrt N)
 * 
 *  시간 복잡도를 어떻게 잡아야 할지 모르겠네요...
 *  일단 인풋의 최댓값이 1억이니까 그것이 소수인지 확인할 때는 10000 이하의 소수만 있으면 되죠.
 *  그래서 먼저 에라토스테네스의 체로 10000까지의 소수를 저장하고,
 *  1자리부터 8자리까지 가능한 팰린드롬을 만들어서 이게 소수인지 판별합니다.
 *  그렇게 소수인팰린드롬을 구하면 저장해놓고, 마지막에 입력받은 a와 b 사이의 수만
 *  모두 출력했습니다.
 * 
 *  P.S. 처음에 이 문제에서 '맞은 사람' 목록을 볼 때, 사람들의 코드 길이가 매우 긴 것을 보고,
 *    미리 다 구해서 데이터베이스화 했다고 생각하고 따라해서 3등했습니다 ㅋㅋㅋ
 */

#include <cstdio>
#include <vector>
using namespace std;

bool noPrime[10001];
vector <int> prime;
vector <int> prime_pal;

// 1 ~ 10000 사이의 소수를 저장하는 함수
void get_prime() {
  for (int i = 2; i <= 10000; ++i) {
    if (!noPrime[i]) {
      prime.push_back(i);
      for (int j = i; i * j <= 10000; ++j) noPrime[i * j] = true;
    }
  }
}

// 주어진 수가 소수인지 판별하는 함수
bool is_prime(int n) {
  for (int i = 0; prime[i] * prime[i] <= n; ++i) 
    if (n % prime[i] == 0) return false;
  return true;
}

// 한 자리씩 쓰여있는 정수 배열을 받아서 완전한 정수로 만들어주는 함수
int get_number(int *a, int len) {
  int ret = 0, i;
  for (i = 0; i < len; ++i) ret = ret * 10 + a[i];
  return ret;
}

// 범위 내의 가능한 팰린드롬을 모두 만들어서 소수인 것만 저장하는 함수
void get_prime_palindrome() {
  int arr[8], num;
  // 범위가 1억 이하이니까 가능한 팰린드롬은 한 자릿수부터 여덟 자릿수까지 가능
  for (int len = 1; len < 9; ++len) {
    // 2를 제외한 모든 소수는 홀수이므로 가장 끝수는 홀수로 한정
    for (int i = 1; i <= 9; i += 2) {
      arr[0] = arr[len - 1] = i;
      // 길이가 2보다 길면 더 진행
      if (len > 2) {
        for (int j = 0; j < 10; ++j) {
          arr[1] = arr[len - 2] = j;
          // 길이가 4보다 길면 더 진행
          if (len > 4) {
            for (int k = 0; k < 10; ++k) {
              arr[2] = arr[len - 3] = k;
              // 길이가 6보다 길면 더 진행
              if (len > 6) {
                for (int l = 0; l < 10; ++l) {
                  arr[3] = arr[len - 4] = l;
                  if (is_prime((num = get_number(arr, len)))) prime_pal.push_back(num);
                }
              } else if (is_prime((num = get_number(arr, len)))) prime_pal.push_back(num);
            }
          } else if (is_prime((num = get_number(arr, len)))) prime_pal.push_back(num);
        }
      } else if (is_prime((num = get_number(arr, len)))) prime_pal.push_back(num);
    }
  }
}

int main(int argc, char *argv[]) {
  int a, b, i;
  scanf("%d %d", &a, &b);
  get_prime();
  get_prime_palindrome();
  for (i = 0; i < prime_pal.size(); ++i) {
    if (a <= prime_pal[i] && prime_pal[i] <= b) printf("%d\n", prime_pal[i]);
    else if (prime_pal[i] > b) break;
  }
  return !printf("-1\n");
}