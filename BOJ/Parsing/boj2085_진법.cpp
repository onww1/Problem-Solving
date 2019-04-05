#include <cstdio>
#include <cstring>
typedef long long ll;

char in[36]; 
int len, ans;

// base의 시작 index가 b라고 했을 때, 가능한 경우의 수를 센다.
int count(int b) {
  int DP[36] = {1};
  if (len > 2 * b) {  // base가 모든 경우의 수보다 클 수 밖에 없는 경우는 모두 세어준다.
    for (int i = 0; i < b; ++i) {
      if (in[i] == '0') { // 0으로 시작하면 뒤에 수가 있으면 안되므로 한 자릿 수만 세준다.
        DP[i+1] += DP[i];
        continue;
      }
      for (int j = i; j < b; ++j) DP[j+1] += DP[i];
    }
  } else {  // base가 작은 경우가 생기는 상황은 base를 구해줘서 체크한다.
    ll base = 0, val;
    for (int i = b; in[i]; ++i) base = base * 10 + in[i] - '0';
    for (int i = 0; i < b; ++i) {
      if (in[i] == '0') {
        DP[i+1] += DP[i];
        continue;
      }
      val = 0LL;
      for (int j = i; j < b && j < i + 17; ++j) {
        val = val * 10LL + in[j] - '0';
        if (val < base) DP[j+1] += DP[i];
        else break;
      }
    }
  }
  return DP[b];
}

int main(int argc, char *argv[]) {
  scanf("%s", in);
  len = strlen(in);
  if (in[0] == '0') return !printf("%d\n", in[1] == '0' ? 0 : 1);
  for (int i = 1; i < len; ++i) {
    if (in[i] == '0') continue;
    ans += count(i);
  }
  return !printf("%d\n", ans);
}
