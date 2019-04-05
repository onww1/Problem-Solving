/*
 *  BOJ 1033. 칵테일
 * 
 *  이 문제 하나 풀려고 유리수까지 구현했네요 ㅋㅋ 
 *  코드를 보시면 금방 아실 수 있겠지만 그냥 저는 깡으로 유리수를 구현해서
 *  비율을 반영해 나갔습니다. 어떤 한 비율이 바뀌면 이전에 입력되었던 다른 비율들도 
 *  그것에 맞게 반영이 되어야 하기 때문에 이전에 들어왔던 관계들에 대해서도 저장을 해두고,
 *  바뀌었을 때, 그것과 관련된 모든 비율들에 반영을 해나갔습니다.
 * 
 *  그렇게 최종적으로 완성된 비율에서 분모의 최소 공배수를 구해 그 값들을 모두 곱해서 
 *  나오는 값들을 차례대로 출력하도록 만들었습니다.
 */

#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll get_gcd(ll a, ll b) { return a % b ? get_gcd(b, a % b) : b; }
ll get_lcm(ll a, ll b) { return a / get_gcd(a, b) * b; }

// 유리수
struct rational {
  ll numerator, denominator;
  rational() { numerator = 0LL, denominator = 1LL; }
  rational(ll n) { numerator = n, denominator = 1LL; }
  rational(ll n, ll d) { 
    ll gcd_val = get_gcd(n, d);
    numerator = n / gcd_val;
    denominator = d / gcd_val; 
  }
  rational operator* (const rational &other) {
    ll n = this->numerator * other.numerator;
    ll d = this->denominator * other.denominator;
    return rational(n, d);
  }
  rational operator/ (const rational &other) {
    ll n = this->numerator * other.denominator;
    ll d = this->denominator * other.numerator;
    return rational(n, d);
  }
};

rational ratio[10];
vector <int> relation[10];

// 어떤 한 재료에 대해서 비율이 바뀌면 그것과 관련된 애들도 모두 바꿔주는 함수입니다.
void reflection(int src, rational &factor, vector<bool> visited) {
  visited[src] = true;
  for (auto it : relation[src]) {
    if (!visited[it]) {
      ratio[it] = ratio[it] * factor;
      reflection(it, factor, visited);
    }
  }
}

int main(int argc, char *argv[]) {
  int n, a, b, p, q, i;
  scanf("%d", &n);
  if (n == 1) return !printf("1\n"); // n이 1이면 그 재료 1만 필요합니다.

  // 처음에 모든 비율은 1로 초기화 합니다.
  for (i = 0; i < n; ++i) ratio[i] = rational(1LL);
  for (i = 1; i < n; ++i) {
    scanf("%d %d %d %d", &a, &b, &p, &q);
    rational factor = rational(p, q) * ratio[b] / ratio[a]; // 몇을 곱해야 하는지 factor를 구합니다.
    ratio[a] = ratio[a] * factor; // 먼저 a에 factor를 반영합니다.
    reflection(a, factor, vector<bool>(n, false)); // a와 관련된 모든 것들에 factor를 반영합니다.
    relation[a].push_back(b); // a와 b의 관게를 추가합니다.
    relation[b].push_back(a);
  }

  // 전체 최소 공배수를 구하고 계산하여 출력합니다.
  ll total_lcm = get_lcm(ratio[0].denominator, ratio[1].denominator);
  for (i = 2; i < n; ++i) total_lcm = get_lcm(total_lcm, ratio[i].denominator);
  for (i = 0; i < n; ++i) printf("%lld ", total_lcm / ratio[i].denominator * ratio[i].numerator);
  return !printf("\n");
}
