#include <cstdio>
char in[1000010];
int H, V;
int main() {
	scanf(" %s", in);
	for (int i = 0; in[i]; ++i) {
		if (in[i] == 'H') ++H;
		else if (in[i] == 'V') ++V;
	}
	H %= 2;
	V %= 2;
	if (H and V) printf("4 3\n2 1\n");
	else if (H and !V) printf("3 4\n1 2\n");
	else if (!H and V) printf("2 1\n4 3\n");
	else printf("1 2\n3 4\n");
	return 0;
}