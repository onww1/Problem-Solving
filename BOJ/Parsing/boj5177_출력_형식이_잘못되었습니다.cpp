/*
 *  BOJ 5177. 출력 형식이 잘못되었습니다
 * 
 *  정말 귀찮은 문제인 것 같습니다. 죄송합니다.
 *  저는 서로 구분하지 않는 문자들은 서로 같은 문자로 치환시켜서 앞에서부터
 *  차례대로 비교해 나가는 식으로 했습니다. 이 과정에서 서로 문자가 다른 상황이 오면
 *  그 상황을 체크합니다. 이때 공백이 아닌 그냥 문자끼리 다른거면 무조건 다른 것이고,
 *  만약 하나가 공백이라면 다른 하나가 처음 인덱스이거나, 이전 글자랑 현재 글자가 
 *  문자열(알파벳, 숫자)와 관련된 것이 아니라면 괜찮은 상황이므로 공백을 다 받아서 없애줍니다.
 *  그렇게 공백을 없앴는데도 다시 비교했을 때 다르면 그것은 다른 문자열이므로 같지 않다는
 *  표시를 해주고 while문을 나옵니다. 
 *  그리고 그 밖에서 valid 했는지에 따라서 적절히 출력해 주었습니다.
 */

#include <iostream>
#include <string>
using namespace std;

// 문자열을 확인하기 위한 함수
char toUpper(char c) { return 'a' <= c && c <= 'z' ? c - 'a' + 'A' : c; }
bool isAlpha(char c) { return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'); }
bool isNumber(char c) { return '0' <= c && c <= '9'; }
bool isAboutString(char c) { return isAlpha(c) || isNumber(c); }

// 서로 구분하지 않는 문자들을 같은 문자로 치환하는 함수 
char parse(char c) {
  if (c == ' ' || c == '\t') return ' ';
  else if (c == '}' || c == ')' || c == ']') return ')';
  else if (c == '{' || c == '(' || c == '[') return '(';
  else if (isAlpha(c)) return toUpper(c);
  else if (c == ',' || c == ';') return ',';
  else return c;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  char c1, c2;
  int k, t, i, p1, p2, l1, l2;
  string s1, s2;

  cin >> k;
  getline(cin, s1);
  for (t = 1; t <= k; ++t) {
    getline(cin, s1);
    getline(cin, s2);
    l1 = s1.size(), l2 = s2.size();
    p1 = 0        , p2 = 0;

    bool valid = true;
    while (p1 < l1 && p2 < l2) {
      // 현재 위치의 문자를 파싱해서 받습니다.
      c1 = parse(s1[p1++]); 
      c2 = parse(s2[p2++]); 

      // 만약 두 문자가 같지 않다면 내부를 들여다 봅니다.
      if (c1 != c2) {
        // c1이 공백 문자고, s2가 현재 첫 인덱스이거나 현재 문자와 이전 문자가 모두 문자열과 관련이 없으면 공백을 모두 지워줍니다.
        if (c1 == ' ' && (p2 == 1 || !isAboutString(s2[p2-2]) || !isAboutString(s2[p2-1]))) {
          while (c1 == ' ' && p1 < l1) 
            c1 = parse(s1[p1++]);
        }
        // c2가 공백 문자고, s1이 현재 첫 인덱스이거나 현재 문자와 이전 문자가 모두 문자열과 관련이 없으면 공백을 모두 지워줍니다.
        else if (c2 == ' ' && (p1 == 1 || !isAboutString(s1[p1-2]) || !isAboutString(s1[p1-1]))) {
          while (c2 == ' ' && p2 < l2) 
            c2 = parse(s2[p2++]);
        }

        // 위와 같이 공백을 다 지웠는데도 문자가 다르면 아예 다른 문자열이므로 valid에 false를 넣습니다.
        if (c1 != c2) {
          valid = false;
          break;
        }
      }
    }

    // valid의 값에 따라서 적절히 출력해줍니다.
    if (t > 1) printf("\n");
    printf("Data Set %d: %s\n", t, valid ? "equal" : "not equal");
  }
  return 0;
}