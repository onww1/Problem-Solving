#include <iostream>
using namespace std;

int up(int a) {
	int t = 1, cur;
	while (a / t) {
		cur = a / t % 10;
		if (cur == 5) 
			a += t;
		t *= 10;
	}
	return a;
}

int down(int a) {
	int t = 1, cur;
	while (a / t) {
		cur = a / t % 10;
		if (cur == 6)
			a -= t;
		t *= 10;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;

	cout << (down(a) + down(b)) << ' ' << (up(a) + up(b)) << '\n';

	return 0;
}