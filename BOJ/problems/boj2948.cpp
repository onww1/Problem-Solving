#include <cstdio>
char A[7][20] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int D, M, C;
int main() {
	scanf("%d %d", &D, &M);
	for (int i = 1; i < M; ++i) C += day[i];
	C += (D - 1);
	return !printf("%s\n", A[C % 7]);
}