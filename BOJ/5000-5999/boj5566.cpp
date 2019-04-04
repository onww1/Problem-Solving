/*
 *  BOJ 5566. 주사위 게임
 *
 *  시간 복잡도 : O(M)
 *  공간 복잡도 : O(N)
 *
 *  MAP에 대한 정보를 다 받고, 이동하는 경우에 대해서 N - 1을 넘는 상황을 체크만 하면 됩니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1000;
int N, M, MAP[MAX], ans;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%d", MAP + i);

    bool finished = false;
    for (int i = 0, D, cur = 0; i < M; ++i) {
        scanf("%d", &D);
        // 이미 도착점에 도착했으면 종료.
        if (finished) continue;
        ans++;

        // 도착점에 도착하면 finished를 찍고 끝낸다.
        if (cur + D >= N - 1 || cur + D + MAP[cur + D] >= N - 1) {
            finished = true;
            continue;
        }

        // 이동
        cur = cur + D + MAP[cur + D];
    }

    // 정답 출력
    printf("%d\n", ans);
    return 0;
}