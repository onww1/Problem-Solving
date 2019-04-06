#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char num1[10001];
	char num2[10001];
	char res[10002] = { 0, };

	scanf("%s %s", num1, num2);
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	int len=0;
	while (len1 > 0 && len2 > 0) {
		int a = num1[len1 - 1] - '0';
		int b = num2[len2 - 1] - '0';
		res[len + 1] = (res[len] + a + b)/10;
		res[len] =  (res[len] + a + b) % 10;
		len1--; len2--; len++;
	}

	if (len1 > 0) {
		while (len1 > 0) {
			int a = num1[len1 - 1] - '0';
			res[len + 1] = (res[len] + a)/10;
			res[len] = (res[len] + a)%10;
			len1--; len++;
		}
	}
	else {
		while (len2 > 0) {
			int a = num2[len2 - 1] - '0';
			res[len + 1] = (res[len] + a)/10;
			res[len] = (res[len] + a)%10;
			len2--; len++;
		}
	}
	if (res[len]) len++;

	for (int i = len-1; i >= 0; i--) {
		printf("%c", res[i] + '0');
	}
	printf("\n");

	return 0;
}