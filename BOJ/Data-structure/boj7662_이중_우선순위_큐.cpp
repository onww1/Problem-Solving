#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

const int BS = 1 << 17;
char buf[BS];
inline char read() {
    static int idx = BS;
    if (idx == BS) {
        int nidx = fread(buf, 1, BS, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return buf[idx++];
}
inline int readInt() {
    int sum = 0, flag = 0;
    char now = read();
    while (now == ' ' || now == '\n') now = read();
    if (now == '-') flag = 1, now = read();
    while ('0' <= now && now <= '9') sum = sum * 10 + now - '0', now = read();
    return flag ? -sum : sum;
}

int T, K, I;
char D;
multiset <int> S;

int main(int argc, char *argv[]) {
    T = readInt();
    while (T--) {
        S.clear();
        K = readInt();
        while (K--) {
            D = read();
            while (D == ' ' || D == '\n') D = read();
            I = readInt();
            if (D == 'I') S.insert(I);
            else {
                if (S.begin() == S.end()) continue;
                else if (I == -1) S.erase(S.begin());
                else S.erase(--S.end());
            }
        }
        if (S.begin() == S.end()) puts("EMPTY");
        else printf("%d %d\n", *(--S.end()), *S.begin());
    }

    return 0;
}