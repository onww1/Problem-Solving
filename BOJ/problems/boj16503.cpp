#include <iostream>
using namespace std;

int calc(int A, char op, int B) {
	if (op == '+') {
		return A + B;
	}
	else if (op == '-') {
		return A - B;
	}
	else if (op == '*') {
		return A * B;
	}
	else {
		return A / B;
	}
}

int main(int argc, char const *argv[])
{
	int A, B, C;
	char op1, op2;

	cin >> A >> op1 >> B >> op2 >> C;

	int res1 = calc(calc(A, op1, B), op2, C);
	int res2 = calc(A, op1, calc(B, op2, C));

	if (res1 < res2)
		cout << res1 << '\n' << res2 << '\n';
	else
		cout << res2 << '\n' << res1 << '\n';

	return 0;
}