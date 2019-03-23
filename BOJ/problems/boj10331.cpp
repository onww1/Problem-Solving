/* 
 *  BOj 10331. Miscalculation
 *
 *  시간 복잡도 : O(N)
 *  공간 복잡도 : O(N)
 *
 *  문제에서 요구하는 대로 곱셈을 더 먼저하는 계산과 왼쪽에서 오른쪽으로 순서대로 계산하는 것을
 *  구현만 하면 되는 문제였습니다.
 */

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

char in[18];
int A, M, L;

// 곱셈을 먼저 하는 계산
int multiplication_first_rule() {
    int ret = in[0] - '0';
    vector <int> num;
    for (int i = 1; in[i]; ++i) {
        if (in[i] == '+') { // 덧셈을 만나면 여태까지 계산된 것들을 스택에 넣어줌.
            num.push_back(ret);
            ret = in[++i] - '0';
        } else if (in[i] == '*') {  // 곱셈을 만나면 바로 다음 수를 곱해줌.
            ret *= in[++i] - '0';
        }
    }

    // 스택에 쌓여있는 것들을 모두 더해줌
    while (!num.empty()) {
        ret += num.back();
        num.pop_back();
    }

    return ret;
}

int left_to_right_rule() {
    int ret = in[0] - '0';
    for (int i = 1; in[i]; ++i) {
        if (in[i] == '+') ret += (in[++i] - '0');
        else if (in[i] == '*') ret *= (in[++i] - '0');
    }
    return ret;
}

int main(int argc, char *argv[]) {
    scanf(" %s %d", in, &A);
    M = multiplication_first_rule();
    L = left_to_right_rule();
  
    bool MA = (M == A), LA = (L == A);
    if (MA && LA) puts("U");
    else if (MA) puts("M");
    else if (LA) puts("L");
    else puts("I");

    return 0;
}