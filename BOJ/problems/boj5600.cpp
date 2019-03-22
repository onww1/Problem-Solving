/*
 *  BOJ 5600. 품질검사
 *
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N)
 *
 *  입력을 받으면서 정상이라고 판별된 것의 부품은 모두 정상이므로 그것들을 모두 정상으로 표시해줍니다.
 *  그리고 고장이라고 판정된 것들은 큐에 넣어두고, 큐를 돌면서 정상인 것들이 2개 있으면 나머지 하나는
 *  무조건 고장이므로 그것을 고장으로 표시해줍니다. 그렇게 큐를 한 바퀴 돌면서 변한 것이 있었으면 
 *  큐를 한 바퀴 더 돌립니다. 그렇게 변확가 없을 때까지 큐를 돌리고 나면 답을 구할 수 있습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

int A, B, C, N, size, status[301];
queue <piii> Q;

int main(int argc, char *argv[]) {
    scanf("%d %d %d %d", &A, &B, &C, &N);
    A += B + C;
    fill(status + 1, status + A + 1, 2);    // 일단 모든 부품들을 알 수 없는 상태로 설정
    
    for (int t = 0, i, j, k, r; t < N; ++t) {
        scanf("%d %d %d %d", &i, &j, &k, &r);
        if (r) { status[i] = status[j] = status[k] = 1; }   // 정상이면 모두 정상으로 표시
        else Q.push({i, {j, k}});   // 고장이면 큐에 넣음.
    }

    bool changed = true;
    while (1) {
        if (size == 0) {
            if (changed) {  // 변한 것이 있었으면 사이즈를 다시 받아주고, 변화를 해제함.
                size = Q.size();
                changed = false;
            } else break;   // 변한게 없으면 무한루프 종료
        }

        piii cur = Q.front();
        Q.pop(); size--;

        // 세 부품 중에서 두 가지가 정상이면 나머지는 고장임.
        if (status[cur.X] == 1 && status[cur.Y.X] == 1) {   
            status[cur.Y.Y] = 0;
            changed = true;
        } else if (status[cur.X] == 1 && status[cur.Y.Y] == 1) {
            status[cur.Y.X] = 0;
            changed = true;
        } else if (status[cur.Y.X] == 1 && status[cur.Y.Y] == 1) {
            status[cur.X] = 0;
            changed = true;
        } else Q.push(cur);
    }

    for (int i = 1; i <= A; ++i) printf("%d\n", status[i]);
    return 0;
}