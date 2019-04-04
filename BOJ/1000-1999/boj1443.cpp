/*
 *  BOJ 1443. 망가진 계산기
 *
 *  시간 복잡도 : O(8HP)
 *  공간 복잡도 : O(1)
 *
 *  D의 값을 이용해 LIMIT 값을 만들어 둔 다음, 백트래킹을 하였습니다.
 *  이때, 숫자를 2 * 3을 하든, 3 * 2를 하든 같은 결과이므로 경우의 수를 줄이기 위해
 *  곱하는 수의 순서를 증가하는 순서로 곱할 수 있도록 만들었습니다.
 */

#include <algorithm>
#include <cstdio>
using namespace std;

int D, P, LIM = 1, mx = -1;

void solve(int T, int prev, int N) {
    // P번 곱했을 때, mx 갱신
    if (T == P) {
        mx = max(mx, N);
        return;
    }

    // 이전에 곱했던 수부터 시작해서 9까지 곱해봄
    for (int i = prev; i <= 9; ++i) {
        int num = N * i;
        if (num < LIM) solve(T + 1, i, num);
        else break;
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &D, &P);
    for (int i = 1; i <= D; ++i) LIM *= 10; // LIMIT 값 계산
    solve(0, 2, 1); // 백트래킹
    printf("%d\n", mx); // 결과 출력
    return 0;
}