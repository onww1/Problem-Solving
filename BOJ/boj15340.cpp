#include <iostream>
using namespace std;

int min(int a, int b, int c) {
	if (a > b) return b > c ? c : b;
	else return a > c ? c : a;
}

int aaa(int a, int b) {
	return a * 30 + b * 40;
}

int bbb(int a, int b) {
	return a * 35 + b * 30;
}

int ccc(int a, int b) {
	return a * 40 + b * 20;
}

int solve(int a, int b) {
	int c1 = aaa(a, b);
	int c2 = bbb(a, b);
	int c3 = ccc(a, b);
	return min(c1, c2, c3);
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int a, b;
	while (1) {
		cin >> a >> b;
		if (!a && !b) break;
		cout << solve(a, b) << '\n';
	}
	return 0;
}