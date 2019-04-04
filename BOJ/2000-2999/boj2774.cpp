#include <cstdio>
#include <set>
using namespace std;

int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		set <int> s;
		while (N) {
			s.insert(N % 10);
			N /= 10;
		}
		printf("%lu\n", s.size());
	}
	return 0;
}