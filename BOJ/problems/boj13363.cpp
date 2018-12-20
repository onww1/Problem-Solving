#include <iostream>
using namespace std;

int get_abs(int a) { return a > 0 ? a : -a; }

int main(int argc, char const *argv[])
{
	int A, B;
	cin >> A >> B;

	int cw = (A - B + 360) % 360;
	int ccw = 360 - cw;
	cout << (cw < ccw ? -cw : ccw) << '\n';
	return 0;
}