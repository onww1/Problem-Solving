#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

char map[64][65];

string solve(int r, int c, int w) {
	if (w == 1) {
		return map[r][c] == '1' ? string("1") : string("0");
	}

	int half = w/2;
	string upperleft = solve(r, c, half);
	string upperright = solve(r, c+half, half);
	string lowerleft = solve(r+half, c, half);
	string lowerright = solve(r+half, c+half, half);

	if (upperleft.length() == 1 &&
		upperleft.compare(upperright) == 0 &&
		upperleft.compare(lowerleft) == 0 &&
		upperleft.compare(lowerright) == 0 ) {
		return upperleft;
	}
	return string("(") + upperleft + upperright + lowerleft + lowerright + string(")");
}

int main() {
	int N;

	cin >> N;
	for (int i=0; i<N; i++) {
		scanf("%s", map[i]);
	}

	cout << solve(0, 0, N) << '\n';

	return 0;
}