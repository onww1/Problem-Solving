#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d.%d\n", (a/2)-b, a%2?5:0);
	return 0;
}