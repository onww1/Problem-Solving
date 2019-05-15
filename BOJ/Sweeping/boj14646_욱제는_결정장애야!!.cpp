#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5;
int N, mx, cnt;
bool chk[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d", &N); N *= 2;
    for (int i = 0, A; i < N; ++i) {
        scanf("%d", &A);
        if (!chk[A]) {
            chk[A] = true;
            cnt++;
            mx = max(mx, cnt);
        } else cnt--;
    }

    printf("%d\n", mx);
    return 0;
}