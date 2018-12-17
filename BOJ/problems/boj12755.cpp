#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[1'000'010] = {0,};
	int N;
	scanf("%d", &N);

	int i=1;
	while (strlen(str) < N) {
		sprintf(str, "%s%d", str, i);
		i++;

		if (strlen(str) > 1'000'000) {
			sprintf(str, "%s", str + 1'000'000);
			printf("%s\n", str);
			N -= 1'000'000;
		}
	}

	printf("%c\n", str[N-1]);
	return 0;
}