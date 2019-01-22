#include <cstdio>
#include <cstring>
using namespace std;

char in[1050], rm[1050], cnt[10];
int main(int argc, char *argv[]) {
	int i, j, l1, l2;
	scanf("%s %s", in, rm);
	l1 = strlen(in);
	l2 = strlen(rm);
	for (i = 0; i < l2; ++i) ++cnt[rm[i]];
	for (i = 0; i < l1 - 1; ++i) {
		if (cnt[in[i]] && in[i] < in[i+1]) cnt[in[i]]--, in[i] = -1;
	}
	for (i = l1 - 1; i > 0; --i) {
		if (in[i] >= 0 && cnt[in[i]] && in[i] >= in[i-1]) cnt[in[i]]--, in[i] = -1;
	}
	for (i = 0; i < l1; ++i) if (in[i] != -1) printf("%c", in[i]);
	puts("");
	return 0;
}