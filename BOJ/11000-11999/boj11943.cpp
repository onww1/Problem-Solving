#include <iostream>
using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
	int a1, o1, a2, o2;
	cin >> a1 >> o1 >> a2 >> o2;
	cout << (get_min(a1 + o2, a2 + o1)) << '\n';
	return 0;
}