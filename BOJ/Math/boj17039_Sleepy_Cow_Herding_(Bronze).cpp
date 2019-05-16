#include <algorithm>
#include <cstdio>
using namespace std;

int pos[3], mn, mx;

int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; ++i) scanf("%d", pos + i);
    sort(pos, pos + 3);

    if (pos[0] + 1 == pos[1] && pos[1] + 1 == pos[2]) 
        return !printf("0\n0\n");

    if (pos[1] - pos[0] == 2 || pos[2] - pos[1] == 2) mn = 1;
    else mn = 2;

    mx = max(pos[1] - pos[0], pos[2] - pos[1]) - 1;

    printf("%d\n%d\n", mn, mx);
    return 0;
}