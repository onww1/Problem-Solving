#include <cstdio>
int main() {
	char in[20];
	scanf(" %s", in);
	int A = 0, m = 0, flg = 0;
	for (int i = 0; in[i]; ++i) {
		if (in[i] == '-') {
			m = 1;
			continue;
		}
		if (in[i] == 'x') {
			flg = 1;
			break;
		}
		A = A * 10 + in[i] - '0';
	}
	if (flg) {
		if (A) printf("%d\n", m ? -A : A);
		else printf("%d\n", m ? -1 : 1);
	} else printf("0\n");
	return 0;
}