#include <cstdio>

int A, B, L;
char C[105];

int main(int argc, char *argv[]) {
    scanf("%d %d %s", &A, &B, C);
    for (L = 0; C[L]; ++L);
    if ((C[L - 1] - '0') % 2) A ^= B;
    printf("%d\n", A);
    
    return 0;
}