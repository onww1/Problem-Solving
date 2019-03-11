#include <cstdio>
#include <cstring>
char in[2][10], op[10];
bool A, B;
int main() {
	scanf("%s %s %s", in[0], op, in[1]);
	A = (strcmp(in[0], "true") == 0);
	B = (strcmp(in[1], "true") == 0);
	if (strcmp(op, "AND") == 0) printf("%s\n", (A && B) ? "true" : "false");
	else printf("%s\n", (A || B) ? "true" : "false");
	return 0;
}