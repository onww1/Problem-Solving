#include <iostream>
#include <string>
using namespace std;

string judge(int a, int b, int c) {
	if (a + b + c != 180) return "Error";
	else {
		if (a == b && b == c) return "Equilateral";
		else if (a == b || b == c || a == c) return "Isosceles";
		else return "Scalene";
	}
}

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << judge(a, b, c) << '\n';
	return 0;
}