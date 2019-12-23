#include <stdio.h>
#include <time.h>

extern int test(char* A[1000000][5], char* B[1000000][5]);

static char* A[1000000][5];
static char* dummy1[2357];
static char* B[1000000][5];
static char* dummy2[1468];

static unsigned long long seed = 5ULL; // seed can be changed

static unsigned int random(void)
{
	return ((unsigned int)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}

int main(void)
{
	static const char* const card[25] =
	{
	   "11", "12", "13", "14", "15",
	   "21", "22", "23", "24", "25",
	   "31", "32", "33", "34", "35",
	   "41", "42", "43", "44", "45",
	   "51", "52", "53", "54", "55",
	};

	static int num[25];
	static int answer = 0;

	for (register int c = 0; c < 25; ++c)
		num[c] = c;

	time_t SCORE = 0;

	for (register int tc = 1; tc <= 10; ++tc)
	{
		for (register int c = 0; c < 1000000; ++c)
		{
			for (int l = 0; l < 10; ++l)
			{
				register int t1 = random() % 25;
				register int t2 = random() % 25;
				int t = num[t1];

				num[t1] = num[t2];
				num[t2] = t;
			}

			for (register int n = 0; n < 5; ++n)
			{
				A[c][n] = (char*)card[num[n]];
				B[c][n] = (char*)card[num[5 + n]];
			}
		}

		time_t start = clock();

		answer = test(A, B);

		SCORE += ((clock() - start) / (CLOCKS_PER_SEC / 1000));

		printf("#%d %d\n", tc, answer);
	}

	printf("SCORE : %d (ms)\n", (int)SCORE);

	return 0;
}

int rank[3126], remain[3126], v[3126], arr[5], vis, ra, re;

void dfs(int visited, int sum) {
	if (visited == 31) {
		rank[sum] = ra;
		remain[sum] = re;
		return;
	}

	if (v[sum] == vis) return;
	v[sum] = vis;

	for (int i = 0; i < 5; ++i) {
		if (visited & (1 << i)) continue;
		dfs(visited + (1 << i), sum * 5 + arr[i]);
	}
}

int test(char* A[1000000][5], char* B[1000000][5])
{
	int ret = 0;

	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		arr[0] = i;
		sum = i;
		for (int j = 0; j < 5; ++j) {
			arr[1] = j;
			sum = sum * 5 + j;
			for (int k = 0; k < 5; ++k) {
				arr[2] = k;
				sum = sum * 5 + k;
				for (int l = 0; l < 5; ++l) {
					arr[3] = l;
					sum = sum * 5 + l;
					for (int m = 0; m < 5; ++m) {
						arr[4] = m;
						sum = sum * 5 + m;
						if (!rank[sum]) {
							int cnt[5] = {}, ccnt[6] = {5,};
							for (int n = 0; n < 5; ++n) {
								ccnt[cnt[arr[n]]]--;
								cnt[arr[n]]++;
								ccnt[cnt[arr[n]]]++;
							}
							if (ccnt[3]) {
								rank[sum] = 2;
								for (int n = 4; n >= 0; --n) while (cnt[n] && cnt[n] <= 2) {
									remain[sum] = remain[sum] * 5 + n;
									cnt[n]--;
								}
							}
							else if (ccnt[2]) {
								rank[sum] = 5 - ccnt[2];
								for (int n = 4; n >= 0; --n) while (cnt[n]) {
									remain[sum] = remain[sum] * 5 + n;
									cnt[n]--;
								}
							}
							else if (ccnt[4]) {
								rank[sum] = 1;
								for (int n = 4; n >= 0; --n) if (cnt[n] == 1) {
									remain[sum] = n;
									break;
								}
							}
							else if (ccnt[5]) {
								rank[sum] = 6;
								remain[sum] = 0;
							}
							else {
								rank[sum] = 5;
								remain[sum] = 0;
							}
							++vis; ra = rank[sum], re = remain[sum];
							dfs(0, 0);
						}
						sum /= 5;
					}
					sum /= 5;
				}
				sum /= 5;
			}
			sum /= 5;
		}
		sum /= 5;
	}

	for (int i = 0; i < 1000000; ++i) {
		int prv = -1;
		for (int k = 0; k < 2; ++k) {
			int an = 0;
			for (int j = 0; j < 5; ++j) an = an * 5 + A[i][j][k] - '1';
			int bn = 0;
			for (int j = 0; j < 5; ++j) bn = bn * 5 + B[i][j][k] - '1';
			
			if (rank[an] != rank[bn] || remain[an] != remain[bn] || (prv == 5 && rank[an] == 5)) {
				ret++;
				break;
			}
			prv = rank[an];
		}
	}

	return ret;
}
