#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b>> c;

	double result = (double)(a * c) / b;
	printf("%.6lf\n", result);

	return 0;
}