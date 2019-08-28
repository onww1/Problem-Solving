#include <algorithm>
#include <cstdio>
using namespace std;

char in[505], i, s, f;

int main(int argc, char *argv[]) {
    scanf(" %s", in);
    for (i = 0; in[i]; ++i) {
        if (in[i] == 'X') s++;
        else {
            if (s % 2) { f = 1; break; }
            for (int j = i - s; j < i; j += 4, s -= 4) {
                if (s > 2) for (int k = 0; k < 4; ++k) in[j + k] = 'A';
                else for (int k = 0; k < 2; ++k) in[j + k] = 'B';
            }
            s = 0;
        }
    }
    if (s) {
        if (s % 2) f = 1;
        for (int j = i - s; j < i; j += 4, s -= 4) {
            if (s > 2) for (int k = 0; k < 4; ++k) in[j + k] = 'A';
            else for (int k = 0; k < 2; ++k) in[j + k] = 'B';
        }
        s = 0;
    }

    if (f) puts("-1");
    else printf("%s\n", in);
    return 0;
}