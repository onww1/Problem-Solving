#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int* k = new int;
	printf("%s", ((long long)k%5?"Yonsei":"Korea"));
	delete k;
	return 0;
}