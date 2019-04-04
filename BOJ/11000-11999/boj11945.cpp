#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d %d", &N, &M);

	char map[10][11];
	for (int i=0; i<N; ++i) scanf("%s", map[i]);

	for (int i=0; i<N; ++i) {
		for (int j=M-1; j>=0; j--)
			printf("%c", map[i][j]);
		printf("\n");
	}

	return 0;
}