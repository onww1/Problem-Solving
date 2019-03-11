#include <cstdio>
int ans, in;
char op;
int main() {
	scanf("%d", &ans);
	while (1) {
		scanf(" %c", &op);
		if (op == '=') return !printf("%d\n", ans);
		scanf("%d", &in);
		if (op == '+') ans += in;
		else if (op == '-') ans -= in;
		else if (op == '*') ans *= in;
		else if (op == '/') ans /= in;
	}
	return 0;
}