/*
 *  BOJ 4195. 친구 네트워크
 *
 *  시간 복잡도 : O(NlogN)   (map 때문에)
 *  공간 복잡도 : O(N)
 *
 *  친구 관계를 얻으면 각각 map을 이용하여 index를 부여하고, 그 index를 가지고 union-find를 합니다.
 *  이때, 친구 네트워크의 수도 합쳐줌으로써 한 번에 처리를 하도록 합니다.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int MAX = 1e5;
int T, N, od, pa[2 * MAX + 1], F[2 * MAX + 1];
map <string, int> idx;

// 루트를 찾는 함수
int _find(int a) {
    if (pa[a] < 0) return a;
    return pa[a] = _find(pa[a]);
}

// 두 노드를 합쳐주는 함수, 이때 친구수도 합쳐준다.
void _union(int a, int b) {
    int a_root = _find(a);
    int b_root = _find(b);
    if (a_root != b_root) {
        F[a_root] += F[b_root];
        pa[b_root] = a_root;
    }
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        fill(pa, pa + 2 * N + 1, -1);   // pa를 모두 -1로 초기화
        fill(F, F + 2 * N + 1, 1);      // 친구 네트워크를 모두 1로 초기화 (자기 자신)
        od = 0;                         // 새로운 인덱스 줄 때 사용할 변수.

        for (int i = 0; i < N; ++i) {
            string A, B;
            cin >> A >> B;
            int idxA = idx[A], idxB = idx[B];
            if (idxA == 0) idx[A] = ++od, idxA = od;
            if (idxB == 0) idx[B] = ++od, idxB = od;
            _union(idxA, idxB);   // 친구를 합쳐준다.
            printf("%d\n", F[_find(idxA)]); // 합쳐진 상태에서 친구 수를 출력.
        }
    }

    return 0;
}