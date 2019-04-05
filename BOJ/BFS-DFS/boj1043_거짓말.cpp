/*
 *  BOJ 1043. 거짓말
 *
 *  시간 복잡도 : O(NM)
 *  공간 복잡도 : O(N)
 *
 *  진실을 아는 애들을 체크하고, 진실을 말해야 하는 파티를 visited 배열처럼 생각하고, 
 *  BFS를 하면서 진실을 말해야 하는 파티들을 확장해나갔습니다. 그러고 마지막에 과장해도 되는
 *  파티를 카운트해서 출력했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 50;
int N, M, S, truth[MAX + 1];
bool know_truth[MAX + 1];
vector <int> F[MAX + 1], P[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0, P; i < S; ++i) {
        scanf("%d", &P);
        know_truth[P] = true;   // 진실을 아는 친구들을 체크
    }

    queue <int> q;
    for (int i = 0, FN; i < M; ++i) {
        scanf("%d", &FN);
        for (int j = 0, A; j < FN; ++j) {
            scanf("%d", &A);
            F[A].push_back(i);  // A라는 친구에게 i번째 파티를 참여했다고 저장
            P[i].push_back(A);  // i번째 파티에 A라는 친구가 참여했다고 저장
            if (know_truth[A]) {
                truth[i] = true; // 진실을 아는 친구가 있으면 그 파티는 진실을 말함.
                q.push(i);  // BFS를 할 것이므로 큐에 넣는다.
            }
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 파티에 참여했던 친구들을 모두 진실을 아는 친구로 표시
        for (int _friend : P[cur]) {
            if (!know_truth[_friend]) {
                know_truth[_friend] = true;

                // 진실을 모르던 친구였으면 그 친구가 참여한 파티를 큐에 넣어줌
                for (int _party : F[_friend]) {

                    // 진실을 말하지 않아도 되었던 파티를 큐에 넣어줌.
                    if (!truth[_party]) {
                        truth[_party] = true;
                        q.push(_party);
                    }
                }
            }
        }
    }

    // 과장을 해도 되는 파티를 카운트한다.
    int cnt = 0;
    for (int i = 0; i < M; ++i) if (!truth[i]) cnt++;
    printf("%d\n", cnt);
    return 0;
}