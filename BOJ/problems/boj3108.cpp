/*
 *  BOJ 3108. 로고
 *
 *  시간 복잡도 : O(N * (R + C))
 *  공간 복잡도 : O(RC)
 *
 *  연필을 올리는 횟수의 최솟값을 구하는 문제입니다. 
 *  사각형이 서로 연결되어 있다면 연필을 굳이 들지 않고 쭉 그릴 수 있으므로 연결된 사각형들은 
 *  한 번에 그릴 수 있다는 것을 알 수 있습니다. 따라서 서로 떨어져 있는 사각형의 수를 세면 됩니다.
 *  이걸 단순히 맵에 그림을 그려서 해보려고 했는데 좌표가 1차이 나는 것은 인접해 있는 것으로 되어 
 *  BFS에서 분리를 못하겠어서 union-find를 이용해서 같은 좌표를 공유하는 애들은 같은 그룹으로 묶었습니다.
 *  그렇게 해서 최종적으로 그룹의 수를 세어주고, 만약 원점을 지나는 사각형이 있으면 그때는 굳이 들 필요가 없으므로
 *  연필을 올리는 횟수를 1회 빼줘야 합니다. 그렇게 하여 정답을 구했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int MAX = 1001;
int N, MAP[MAX][MAX], pa[1001];
bool O;

// Union-Find !
int _find(int a) {
    if (pa[a] < 0) return a;
    return pa[a] = _find(pa[a]);
}

void _union(int a, int b) {
    int a_root = _find(a);
    int b_root = _find(b);
    if (a_root != b_root) 
        pa[b_root] = a_root;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    memset(pa, -1, sizeof(pa));
    for (int i = 1, x, y, xx, yy; i <= N; ++i) {
        scanf("%d %d %d %d", &x, &y, &xx, &yy);
        // -500 ~ 500이므로 음이 아닌 정수로 만들어주기 위해 모두 500을 더했습니다.
        x  += 500; y  += 500;
        xx += 500; yy += 500;

        // 원점을 지나는지 확인합니다.
        if ((y == 500 || yy == 500) && x <= 500 && 500 <= xx) O = true;
        if ((x == 500 || xx == 500) && y <= 500 && 500 <= yy) O = true;

        // 사각형의 선을 모두 지나가면서 어떤 점이 찍혀있으면 union을 시킵니다.
        for (int j = x; j <= xx; ++j) {
            if (MAP[y][j]) _union(MAP[y][j], i);
            if (MAP[yy][j]) _union(MAP[yy][j], i);
            MAP[y][j] = MAP[yy][j] = i;
        }
        for (int j = y; j <= yy; ++j) {
            if (MAP[j][x]) _union(MAP[j][x], i);
            if (MAP[j][xx]) _union(MAP[j][xx], i);
            MAP[j][x] = MAP[j][xx] = i;
        }
    }    

    // 모든 사각형에 대해서 그룹을 확인하고, 그룹의 수를 세어줍니다.
    set <int> s;
    for (int i = 1; i <= N; ++i) s.insert(_find(i));

    // 그룹의 수에서 만약 원점을 지나면 1을 빼서 출력합니다.
    printf("%d\n", (int)s.size() + (O ? -1 : 0));
    return 0;
}