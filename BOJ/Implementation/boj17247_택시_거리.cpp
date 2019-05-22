#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, M, A;
pii S, E;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
        scanf("%d", &A);
        if (A) {
            if (!S.X) S = {i, j};
            else E = {i, j};
        } 
    }

    printf("%d\n", abs(S.X - E.X) + abs(S.Y - E.Y));
    return 0;
}