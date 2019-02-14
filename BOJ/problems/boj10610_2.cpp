#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char in[100001];
int cnt[10], s;
int main(int argc, char *argv[]) {
	scanf(" %s", in);
	for (int i = 0; in[i]; ++i) {
		cnt[in[i] - '0']++;
		s = (s + (in[i] - '0')) % 3;
	}

	if (s != 0 || cnt[0] == 0) return !printf("-1\n");

	for (int i = 9, p = 0; i >= 0; --i) 
		while (cnt[i]) in[p++] = i + '0', cnt[i]--;
	return !printf("%s\n", in);
}