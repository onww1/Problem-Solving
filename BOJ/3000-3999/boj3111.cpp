/*
 *  BOJ 3111. 검열
 *
 *  시간 복잡도 : O(N + M)
 *  공간 복잡도 : O(N)
 *
 *  우선 입력을 받고, 입력받은 문자열들의 길이를 strlen 함수를 이용하여 구했습니다.
 *  그리고 Text를 모두 deque에 넣어주어서 이후 패턴을 찾을 때 push, pop을 편하게 하도록 만들었습니다.
 *  이후, KMP의 실패함수를 이용하기 위하여 왼쪽에서 오른쪽으로 확인할 때 쓰는 실패함수와
 *  오른쪽에서 왼쪽으로 확인할 때 쓰는 실패함수를 구해서 패턴이 있는지를 더 빨리 확인할 수 있도록 했습니다.
 *  이제 왼쪽에서 오른쪽, 오른쪽에서 왼쪽 순서대로 반복하면서 패턴을 찾는데, 실패함수를 이용해서 탐색하다가
 *  만약 패턴을 찾았으면 패턴의 길이만큼 스택에서 제거하고, 최대 패턴의 길이만큼 스택에서 뽑아서 deque에 
 *  다시 넣어줍니다. 근데 이때, 스택에는 실패함수의 값도 같이 넣기 때문에 실패함수의 값이 0인 점이 있으면
 *  거기까지만 deque에 넣고 거기서 멈추도록 하여, 탐색을 조금 더 빠르게 하도록 했습니다.
 *  그렇게 반복하면 굳이 나중에 deque에 있는 값이 다 빠졌을 때, 두 스택간의 관계를 고려할 필요가 없어집니다.
 *  그렇게 마지막에 왼쪽 스택에 있는 값들을 모두 오른쪽 스택에 넣어주고, 한 번에 결과 배열에 넣어주고 출력했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <deque>
#define X first
#define Y second
using namespace std;
typedef pair<char, int> pci;

const int TMAX = 300001, PMAX = 26;
char P[PMAX], in[TMAX], ans[TMAX];
int idx, LP, LT, PIF[PMAX], PIB[PMAX];

int main(int argc, char *argv[]) {
    stack <pci> F, B;   // 왼쪽, 오른쪽 stack
    deque <char> T;     // Text를 담는 deque

    scanf(" %s %s", P, in);
    LP = strlen(P), LT = strlen(in);    // 문자열 길이 계산
    T = deque<char>(in, in + LT);       // Text를 deque에 넣어줌.

    // 왼쪽에서 오른쪽으로 가는 실패함수 계산
    for (int i = 1, j = 0; i < LP; ++i) {
        while (j > 0 && P[i] != P[j]) j = PIF[j - 1];
        if (P[i] == P[j]) PIF[i] = ++j;
    }
    
    // 오른쪽에서 왼쪽으로 가는 실패함수 계산
    fill(PIB, PIB + LP, LP - 1);
    for (int i = LP - 2, j = LP - 1; i >= 0; --i) {
        while (j < LP - 1 && P[i] != P[j]) j = PIB[j + 1];
        if (P[i] == P[j]) PIB[i] = --j;
    }

    int left = 1, i;
    while (!T.empty()) {
        if (left) { // 왼쪽에서 오른쪽으로 갈 때,
            // 왼쪽 스택에 값이 있으면, top의 실패함수 값부터 시작
            for (i = F.empty() ? 0 : F.top().Y; !T.empty();) {
                char cur = T.front();  // deque의 가장 앞 값을 가져옴
                T.pop_front();
                // 매칭이 안되면 실패함수를 이용하여 앞으로 계속 이동
                while (i > 0 && P[i] != cur) i = PIF[i - 1];
                if (P[i] == cur) i++; // 패턴이랑 값이랑 같으면 i의 값을 1만큼 증가
                F.push({cur, i});   // 왼쪽 스택에 값을 넣어줌.

                // 만약 매칭된 문자의 갯수가 패턴과 같으면, 패턴을 찾은것임
                if (i == LP) {
                    // 패턴의 길이만큼 스택에서 제거
                    for (i = 0; i < LP; ++i) F.pop();
                    // 다음을 위하여 일정 길이만큼 다시 deque에 넣어줌
                    for (i = 0; !F.empty() && i < LP; ++i) {
                        pci node = F.top();
                        T.push_front(node.X); F.pop();
                        if (node.Y == 0) break;
                   }
                   break;
                }
            }
        } else { // 오른쪽에서 왼쪽으로 갈 때,
            // 뒤의 스택에 값이 있으면 그 top의 실패함수 값에서 시작
            for (i = B.empty() ? LP - 1 : B.top().Y; !T.empty();) {
                char cur = T.back();    // deque의 뒤의 값
                T.pop_back();
                // 매칭이 안되면 실패함수를 이용하여 뒤로 이동
                while (i < LP - 1 && P[i] != cur) i = PIB[i + 1];
                if (P[i] == cur) i--;   // 매칭되면 i의 값을 1 감소
                B.push({cur, i});       // 값을 오른쪽 스택에 넣어줌

                // 만약 인덱스가 -1이 되면 모두 매칭된 것임
                if (i == -1) {
                    // 패턴의 길이만큼 스택에서 제거
                    for (i = 0; i < LP; ++i) B.pop();
                    // 다음을 위해 일정 길이만큼 deque에 다시 넣어줌
                    for (i = 0; !B.empty() && i < LP; ++i) {
                        pci node = B.top();
                        T.push_back(node.X); B.pop();
                        if (node.Y == LP - 1) break;
                    }
                    break;
                }
            }
        }

        // 왼쪽, 오른쪽 표시 toggle
        left = 1 - left;
    }

    while (!F.empty()) B.push(F.top()), F.pop();        // 왼쪽 스택의 값을 모두 오른쪽으로 이동
    while (!B.empty()) ans[idx++] = B.top().X, B.pop(); // 하나씩 꺼내어 결과 배열에 저장
    ans[idx] = 0;
    printf("%s\n", ans);    // 결과 출력
    return 0;
}