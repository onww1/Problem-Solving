#include <cstdio>
int a[10], b[10], aa, bb, last;

int main(int argc, char *argv[]) {
    for (int i = 0; i < 10; ++i) scanf("%d", a + i);
    for (int i = 0; i < 10; ++i) scanf("%d", b + i);
    for (int i = 0; i < 10; ++i) {
    	if (a[i] < b[i]) bb += 3, last = 2;
    	else if (a[i] > b[i]) aa += 3, last = 1;
    	else aa++, bb++;
    }

    printf("%d %d\n", aa, bb);
    if (aa > bb) puts("A");
    else if (aa < bb) puts("B");
    else {
    	if (last == 1) puts("A");
    	else if (last == 2) puts("B");
    	else puts("D");
    }

    return 0;
}