#include <cstdio>
int Q, A;

int main(int argc, char *argv[]) {
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &A);
        printf("%d\n", A & (A - 1) ? 0 : 1);
    }
    return 0;
} 