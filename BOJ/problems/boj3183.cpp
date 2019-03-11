#include <cstdio>
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int D, M, Y;
int main() {
	while (1) {
		scanf("%d %d %d", &D, &M, &Y);
		if (!D && !M && !Y) break;
		bool isReap = (Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0), valid = true;
		if (!(1 <= M && M <= 12)) valid = false;
		else if (M == 2) {
			if (!(1 <= D && D <= 28 + (isReap ? 1 : 0))) valid = false;
		}
		else {
			if (!(1 <= D && D <= days[M])) valid = false;
		}
		puts(valid ? "Valid" : "Invalid");
	}
	return 0;
}