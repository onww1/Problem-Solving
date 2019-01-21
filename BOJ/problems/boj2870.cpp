/*
 *  BOJ 2870. 수학숙제
 * 
 *  한 줄에 100자 정도 되고, 이게 전부 숫자라면 100자리의 수가 나오기 때문에
 *  이 문제에서 수는 정수형 변수로는 저장할 수 없고, 문자열로 처리를 해야 합니다.
 * 
 *  수를 저장하는 데에 있어서 편의를 위해 number라는 구조체를 정의하고,
 *  거기에 이 수가 현재 길이가 얼마인지 저장을 했습니다.
 *  그래서 그 길이값을 인덱스로 이용하여 뒤에 추가하는 식으로 나갔습니다.
 *  이 때, 예외처리로는 맨 앞에 0이 나오는 경우 그것을 무시하고 덮어쓰는 정도가 있겠습니다!
 *  
 *  마지막으로는 number 구조체를 비교하는 함수를 정의하고, sort에 넣어서 정렬해주고,
 *  그것을 그대로 출력하였습니다.
 * 
 *  P.S. 문제에 대한 분석이 부족한 상태에서 해서 두 번 정도 틀렸네요 ㅜㅜ
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

// 수를 저장하는 number 구조체 정의
struct number {
  char num[101];
  int len;
  number() { num[0] = 0; len = 0; }
};

// 길이가 같을 때는 strcmp를 이용하여 수를 비교하고, 다른 때는 짧은 것이 앞으로.
bool cmp(number a, number b) {
  if (a.len == b.len) return strcmp(a.num, b.num) < 0;
  return a.len < b.len;
}

bool isDigit(char c) { return '0' <= c && c <= '9'; }

char in[101];
vector <number> numbers;
int main(int argc, char *argv[]) {
  int n, i, len;
  scanf("%d", &n);

  while (n--) {
    scanf(" %s", in);
    len = strlen(in);
    for (i = 0; i < len; ++i) {
      if (isDigit(in[i])) {
        if (!i || !isDigit(in[i-1])) { // 처음이거나 앞 수가 숫자가 아니면 새로운 수를 추가
          number nb;
          nb.num[nb.len++] = in[i];
          nb.num[nb.len] = 0;
          numbers.push_back(nb);
        } else {                       // 앞이 숫자면 마지막 number 뒤에 붙여준다.  
          number &last = numbers.back();
          // 만약 길이가 1이고, 그게 0이라면 덮어쓴다.
          if (last.len == 1 && last.num[0] == '0') last.num[0] = in[i];
          else {
            last.num[last.len++] = in[i];
            last.num[last.len] = 0;
          }
        }
      }
    }
  }

  sort(numbers.begin(), numbers.end(), cmp);
  for (i = 0; i < numbers.size(); ++i)
    printf("%s\n", numbers[i].num);
  return 0;
}