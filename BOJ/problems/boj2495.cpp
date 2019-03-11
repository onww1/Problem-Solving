#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int N, cnt, mx, prev;
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &N);
		cnt = mx = 1;
		prev = -1; 
		while (N) {
			if (N % 10 == prev) {
				cnt++;
				mx = max(mx, cnt);
			}
			else {
				prev = N % 10;
				cnt = 1;
			}
			N /= 10;
		}
		printf("%d\n", mx);
	}
	return 0;
}