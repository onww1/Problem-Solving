#include <cstdio>
using namespace std;

char ans[2000000];
int K, idx;

int main(int argc, char *argv[]) {
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) ans[idx++] = '1';
    for (int i = 0; i < K - 1; ++i) ans[idx++] = '0';
    ans[idx] = 0; printf("%s\n", ans);
    return 0;
}