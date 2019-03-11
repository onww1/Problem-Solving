#include <cstdio>
char in[51];
int pos = 1;
int main() {
	scanf(" %s", in);
	for (int i = 0; in[i]; ++i) {
		if (in[i] == 'A' && pos != 3) pos = 3 - pos;
		else if (in[i] == 'B' && pos != 1) pos = 5 - pos;
		else if (in[i] == 'C' && pos != 2) pos = 4 - pos;
	}
	return !printf("%d\n", pos);
}