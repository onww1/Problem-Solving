#include <cstdio>
int H, P;
int main() {
	while (~scanf("%d %d", &H, &P)) 
		printf("%.2Lf\n", (long double)H / P);
	return 0;
}