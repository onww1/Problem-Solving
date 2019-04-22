#include <stdio.h>
#include <algorithm>
using namespace std;

struct player {
	int cost;
	char name[21];
	bool operator< (const player& other) const {
		return cost > other.cost;
	}
};

int T, N;
player P[100];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d %s", &P[i].cost, P[i].name);
		sort(P, P + N);
		printf("%s\n", P[0].name);
	}
	return 0;
}