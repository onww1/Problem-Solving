/*
 *  BOJ 6581. HTML
 * 
 *  생각보다 구현하기 귀찮았던 문제였던 것 같습니다.
 *  일단 저는 printer라는 구조체를 만들었습니다.
 *  그리고 이 구조체에 계속 word를 추가해 나가는데 
 *  만약 더 추가하려고 할 때, 80자를 넘어간다면 출력하고 비워준 다음,
 *  처음부터 다시 채워주는 것으로 했습니다.
 * 
 *  다른 것들은 그냥 문제에서 주어지는 조건에 맞게 처리했습니다.
 */

#include <cstdio>
#include <cstring>
using namespace std;

struct printer {
  char buf[101];
  int len;
  printer() { buf[0] = 0; len = 0; }
  void reset() { buf[0] = 0; len = 0; } // 프린터를 초기화해주는 함수
  bool empty() { return len == 0; }  // 비어있는지 확인하는 함수

  // 새로운 word를 추가해도 80자를 넘지 않는지 확인하는 함수
  bool canIAppend(char *word) {
    if (len + strlen(word) + (len > 0 ? 1 : 0) > 80) return false;
    return true;
  }

  // 새로운 word를 printer의 buf에 추가시켜주는 함수
  void append(char *word) {
    if (len > 0) buf[len++] = ' ';
    buf[len] = 0;
    strcat(buf, word);
    len = strlen(buf);
  }

  // 현재까지 쌓인 buf를 출력하고 비워주는 함수
  void print() {
    printf("%s\n", buf);
    reset();
  }
};

const char hr[81] = "--------------------------------------------------------------------------------";
char buf[1 << 17];
inline char read() {  // 미리 입력을 다 받아주는 역할
  static int idx = 1 << 17;
  if (idx == 1 << 17) {
    int nidx = fread(buf, 1, 1 << 17, stdin);
    if (!nidx) return 0;
    idx = 0;
  }
  return buf[idx++];
}

int main(int argc, char *argv[]) {
  printer p;
  char word[81], now = read();
  int len = 0;

  while (1) {
    if (now == 0) { // fread로 1 << 17만큼 받으므로 입력이 끝나면 0으로 채워져 있음.
      if (!p.empty()) p.print();  // 남은게 있으면 출력
      break;
    }
    else if (now == ' ' || now == '\t' || now == '\n') { 
      if (len > 0) {  // 공백 문자를 만났을 떄, word에 값이 있으면 append!
        if (!p.canIAppend(word)) p.print();
        p.append(word);
        word[0] = 0; len = 0;
      }
    }
    else if (now == '<') {  // '<'를 만나면 br인지 hr인지 확인하고 상황에 맞게 행동
      if (read() == 'b') p.print();
      else {
        if (!p.empty()) p.print();
        printf("%s\n", hr);
      }
      read(); read(); // "r>"를 지워주는 역할
    }
    else {  // 그냥 문자인 경우 word에 계속 추가
      word[len++] = now;
      word[len] = 0;
    }
    now = read();
  }
  return 0;
}