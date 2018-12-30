#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MOD 1000000007
#define INF 1023456789
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

int parseRomaToDec(char c);
void parseDecToRoma(int n, char roma[]);
int decode(char roma[]);
void encode(int num, char roma[]);

int main(int argc, char *argv[]) {
  char in1[100], in2[100], res[100];
  scanf("%s %s", in1, in2);

  int num1 = decode(in1);
  int num2 = decode(in2);
  encode(num1 + num2, res);
  printf("%d\n", num1 + num2);
  printf("%s\n", res);

  return 0;
}

int parseRomaToDec(char c) {
  if (c == 'I') return 1;
  else if (c == 'V') return 5;
  else if (c == 'X') return 10;
  else if (c == 'L') return 50;
  else if (c == 'C') return 100;
  else if (c == 'D') return 500;
  else if (c == 'M') return 1000;
  return -1;
}

void parseDecToRoma(int n, char roma[]) {
  if (n == 1) strcpy(roma, "I");
  else if (n == 4) strcpy(roma, "IV");
  else if (n == 5) strcpy(roma, "V");
  else if (n == 9) strcpy(roma, "IX");
  else if (n == 10) strcpy(roma, "X");
  else if (n == 40) strcpy(roma, "XL");
  else if (n == 50) strcpy(roma, "L");
  else if (n == 90) strcpy(roma, "XC");
  else if (n == 100) strcpy(roma, "C");
  else if (n == 400) strcpy(roma, "CD");
  else if (n == 500) strcpy(roma, "D");
  else if (n == 900) strcpy(roma, "CM");
  else if (n == 1000) strcpy(roma, "M");
}

int decode(char roma[]) {
  int len = strlen(roma), i, num = 0;
  int cur = parseRomaToDec(roma[0]), next;
  for (i = 1; i < len; ++i) {
    next = parseRomaToDec(roma[i]);
    if (cur < next) {
      num += (next - cur);
      if (i == len - 2) {
        num += parseRomaToDec(roma[++i]);
      } else if (i < len - 2) {
        cur = parseRomaToDec(roma[++i]);
      }
    } else {
      num += cur;
      cur = next;
      if (i == len - 1) num += next;
    }
  }

  if (len == 1) 
    num += cur;
  return num;
}

void encode(int num, char roma[]) {
  int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
  char romas[3];

  roma[0] = 0;
  int idx = 12;
  while (num) {
    if (num >= nums[idx]) {
      parseDecToRoma(nums[idx], romas);
      strcat(roma, romas);
      num -= nums[idx];
    } else {
      --idx;
    }
  }
}

ll get_pow(ll base, ll exp) {
  if (exp == 0ll) return 1ll;
  if (exp == 1ll) return base;

  ll half = get_pow(base, exp/2ll);
  ll res = half * half % MOD;
  if (exp % 2ll) res = res * base % MOD;
  return res;
}

ll get_min(ll a, ll b) { return a < b ? a : b; }
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_abs(ll a) { return a < 0 ? -a : a; }