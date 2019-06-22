#include <cstdio>

const int MAX = 1e5 + 1;
int n, cnt[2];
char in[MAX];

int main(int argc, char *argv[]) {
 	scanf("%d %s", &n, in);
 	for (int i = 0; i < n; ++i) {
 		if (in[i] == 'e') cnt[0]++;
 		else cnt[1]++;
 	} 

 	if (cnt[0] > cnt[1]) puts("e");
 	else if (cnt[0] < cnt[1]) puts("2");
 	else puts("yee");
    return 0;
}