/*
 *  BOJ 1347. 미로 만들기
 *
 *  시간 복잡도 : O(N)
 *  공간 복잡도 : O(K^2)  (K = 100)
 *
 *  내용이 최대 50이니까 최악의 경우 한 쪽으로만 이동한다고 해도 50까지 밖에 못가니까 
 *  처음 위치를 (50, 50)으로 두고 전체 맵의 크기를 101 X 101으로 한 다음 주어진 명령대로
 *  이동하면서 그 칸을 이동할 수 있는 칸으로 만듭니다. 그리고 영역을 계속 갱신해줘서 나중에
 *  출력할 때 이용합니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 100;
const int move_r[] = {1, 0, -1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int curR = 50, curC = 50, curD = 0, N;
char MAP[MAX + 1][MAX + 2], in[MAX + 1];
pii R, C;

int main(int argc, char *argv[]) {
    // 처음 상태 초기화
    memset(MAP, '#', sizeof(MAP));
    MAP[50][50] = '.';
    R = {50, 50}, C = {50, 50};

    scanf("%d %s", &N, in);
    for (int i = 0; in[i]; ++i) {
        if (in[i] == 'R') curD = (curD + 1) % 4;    // 오른쪽으로 턴
        else if (in[i] == 'L') curD = (curD + 3) % 4; // 왼쪽으로 턴
        else {
            // 이동하여 이동할 수 있는 칸이라고 표시
            curR += move_r[curD];
            curC += move_c[curD];
            MAP[curR][curC] = '.';

            // 영역 갱신
            R.X = min(R.X, curR);
            R.Y = max(R.Y, curR);
            C.X = min(C.X, curC);
            C.Y = max(C.Y, curC);
        }
    }

    // 만들어진 미로 출력
    for (int i = R.X; i <= R.Y; ++i) {
        MAP[i][C.Y + 1] = 0;
        printf("%s\n", MAP[i] + C.X);
    }

    return 0;
}