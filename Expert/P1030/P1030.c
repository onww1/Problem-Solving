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

int test(char* A[1000000][5], char* B[1000000][5])
{
	int ret = 0;

	return ret;
}