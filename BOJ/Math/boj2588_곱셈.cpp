#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int A, B;
	cin >> A >> B;

	int first = A * (B % 10);
	int second = A * ((B / 10) % 10);
	int third = A * ((B / 100) % 10);
	cout << first << '\n';
	cout << second << '\n';
	cout << third << '\n';
	cout << (first + 10 * second + 100 * third) << '\n';
	return 0;
}