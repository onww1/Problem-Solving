#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#define X first
#define Y second
using namespace std;
typedef pair<char, int> pci;

const int TMAX = 1000005, PMAX = 40;
int F[PMAX], LT, LP;
char in[TMAX], P[PMAX];
deque <char> T;
vector <pci> S;

int main(int argc, char *argv[]) {
    scanf(" %s %s", in, P);
    LT = strlen(in), LP = strlen(P);
    T = deque <char>(in, in + LT);

    // 실패함수 계산
    for (int i = 1, j = 0; i < LP; ++i) {
        while (j > 0 && P[i] != P[j]) j = F[j - 1];
        if (P[i] == P[j]) F[i] = ++j;
    }

    // 매칭
    for (int i = 0; !T.empty();) {
        char cur = T.front();
        T.pop_front();

        i = S.empty() ? 0 : S.back().Y;
        while (i > 0 && P[i] != cur) i = F[i - 1];
        if (P[i] == cur) i++;
        S.push_back({cur, i});

        if (i == LP) {
            for (int j = 0; j < LP; ++j) S.pop_back();
            for (int j = 0; j < LP && !S.empty(); ++j) {
                pci val = S.back(); S.pop_back();
                T.push_front(val.X);
                if (val.Y == 0) break;
            }
        }
    }

    if (S.empty()) puts("FRULA");
    else {
        in[S.size()] = 0;
        while (!S.empty()) in[S.size() - 1] = S.back().X, S.pop_back();
        printf("%s\n", in);
    }

    return 0;
}