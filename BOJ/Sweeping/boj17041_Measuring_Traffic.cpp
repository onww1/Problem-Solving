#include <algorithm>
#include <cstdio>
using namespace std;

struct seg {
    int type, lo, hi;
} S[100];

int N, f = -1, l = -1;
char in[10];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s %d %d", in, &S[i].lo, &S[i].hi);
        if (in[0] == 'n') {
            S[i].type = 0;
            if (f == -1) f = i;
            l = i;
        }
        else if (in[1] == 'n') S[i].type = 1;
        else S[i].type = 2;
    }

    int lo = S[l].lo, hi = S[l].hi;
    for (int i = l - 1; i >= 0; --i) {
        if (!S[i].type) {
            lo = max(lo, S[i].lo);
            hi = min(hi, S[i].hi);
        } else if (S[i].type == 1) {
            lo -= S[i].hi;
            hi -= S[i].lo;
            lo = max(lo, 0);
            hi = max(hi, 0);
        } else if (S[i].type == 2) {
            lo += S[i].lo;
            hi += S[i].hi;
        }
    }
    printf("%d %d\n", lo, hi);

    lo = S[f].lo, hi = S[f].hi;
    for (int i = f + 1; i < cnt; ++i) {
        if (!S[i].type) {
            lo = max(lo, S[i].lo);
            hi = min(hi, S[i].hi);
        } else if (S[i].type == 1) {
            lo += S[i].lo;
            hi += S[i].hi;
        } else {
            lo -= S[i].hi;
            hi -= S[i].lo;
            lo = max(lo, 0);
            hi = max(hi, 0);
        }
    }
    printf("%d %d\n", lo, hi);
 
    return 0;
}