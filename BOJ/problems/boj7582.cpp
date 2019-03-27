#include <cstdio>
#include <cstring>

char bus[20];
int Z, P, S, A, B;

int main() {
    while (1) {
        scanf(" %s %d", bus, &Z);
        if (!strcmp(bus, "#") && !Z) break;
        scanf("%d %d", &P, &S);
        for (int i = 0; i < S; ++i) {
        	scanf("%d %d", &A, &B);
        	if (P - A + B > Z) P = Z;
        	else if (P - A + B <= 0) P = 0;
        	else P = P - A + B;
        }
        printf("%s %d\n", bus, P);
    }
    return 0;
}