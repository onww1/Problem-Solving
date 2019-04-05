/*
 *  BOJ 1431. 시리얼 번호
 * 
 *  serial이라는 구조체를 정의하고, 그 안에는 시리얼 번호와 길이, 숫자 합을 담았습니다.
 *  길이를 저장한 이유는 strlen이 O(n)이라서 비교할 때마다 호출하면 시간이 더 걸릴 것 같아서
 *  메모리를 소비해서 시간을 줄이자는 생각이었고, 그렇게 하면서 숫자 합을 미리 계산해두어서
 *  sort 함수를 이용했습니다.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct serial {
  char serial_number[51];
  int length, sum;

  serial() {
    serial_number[0] = 0;
    length = sum = 0;
  }
};

bool cmp(serial a, serial b) {
  // 길이 > 숫자 합 > 사전순
  if (a.length == b.length && a.sum == b.sum) return strcmp(a.serial_number, b.serial_number) < 0;
  else if (a.length == b.length) return a.sum < b.sum;
  return a.length < b.length;
}

// serial number에 대한 정보를 미리 계산
void processing(serial &s) {
  s.length = strlen(s.serial_number);
  for (int i = 0; i < s.length; ++i) {
    if ('0' <= s.serial_number[i] && s.serial_number[i] <= '9')
      s.sum += s.serial_number[i] - '0';
  }
}

serial serials[1005];
int main(int argc, char *argv[]) {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf(" %s", serials[i].serial_number);
    processing(serials[i]);
  }
  sort(serials, serials + n, cmp);
  for (i = 0; i < n; ++i) 
    printf("%s\n", serials[i].serial_number);
  return 0;
}