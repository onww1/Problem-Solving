#include <cstdio>
int T, C[4], D[128];
char N[4][20] = {"Coyote", "Bobcat", "Wolf", "Mountain Lion"};
char region[1001], P[1001];

int main() {
	scanf("%d", &T);
	D['B'] = 1, D['C'] = 0, D['M'] = 3, D['W'] = 2;
	while (T--) {
		scanf(" %s %s", region, P);
		C[0] = C[1] = C[2] = C[3] = 0;
		for (int i = 0; P[i]; ++i) C[D[P[i]]]++;
		int mx_idx = 0, cnt = 1;
		for (int i = 1; i < 4; ++i) {
			if (C[mx_idx] * (mx_idx + 1) < C[i] * (i + 1)) {
				cnt = 1;
				mx_idx = i;
			} else if (C[mx_idx] * (mx_idx + 1) == C[i] * (i + 1)) cnt++;
		}
		if (cnt == 1) printf("%s: The %s is the dominant species\n", region, N[mx_idx]);
		else printf("%s: There is no dominant species\n", region);
	}
	return 0;
}