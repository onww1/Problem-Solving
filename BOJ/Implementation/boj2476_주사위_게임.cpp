#include <iostream>
using namespace std;

int judge(int a, int b, int c) {
	if (a == b && b == c) {
		return (10000 + a * 1000);
	}
	else if (a == b) {
		return (1000 + a * 100);
	}
	else if (a == c) {
		return (1000 + a * 100);
	}
	else if (c == b) {
		return (1000 + b * 100);
	}
	else {
		int max = a>b?(a>c?a:c):(b>c?b:c);
		return (max * 100);
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, max = 0;;
	int a, b, c;
	
	cin >> T;
	while (T--) {
		cin >> a >> b >> c;
		int money = judge(a, b, c);
		max = max < money ? money : max;
	}

	cout << max << '\n';
	
	return 0;
}