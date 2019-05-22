#include <algorithm>
#include <cstdio>
using namespace std;

struct cow {
    int ID, pos[4];
} cows[100];

int N, P[100];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", P + i), P[i]--, cows[i].pos[0] = i;
    for (int i = 0; i < N; ++i) scanf("%d", &cows[i].ID);

    for (int i = 1; i <= 3; ++i) {
        for (int j = 0; j < N; ++j) {
            cows[P[j]].pos[i] = cows[j].pos[i - 1];
        }
    }

    sort(cows, cows + N, [](const cow& a, const cow& b) { return a.pos[3] < b.pos[3]; });
    for (int i = 0; i < N; ++i) printf("%07d\n", cows[i].ID);
       
    return 0;
}