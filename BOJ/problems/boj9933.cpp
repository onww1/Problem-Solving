#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int N, L[100];
char W[100][15];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", W[i]);
        L[i] = strlen(W[i]);
    }
  
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if (L[i] == L[j]) {
                int k = 0;
                for (; k < L[i]; ++k) 
                    if (W[i][k] != W[j][L[i] - k - 1]) break;
                if (k == L[i]) return !printf("%d %c\n", L[i], W[i][L[i] / 2]);
            }
        }
    }

    return 0;
}