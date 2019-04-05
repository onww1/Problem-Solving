#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	int max = b-a > c-b ? b-a : c-b;
	cout << (max - 1) << '\n';
	return 0;
}