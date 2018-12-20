#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	int A = 0, B = 0, setA = 0, setB = 0;

	cin >> str;
	int len = str.length();

	for (int i=0; i<len; ++i) {
		if (str[i] == 'A') {
			++A;
			if (A == 21) {
				cout << A << '-' << B << '\n';
				++setA;
				A = B = 0;
			}
		}
		else if (str[i] == 'B') {
			++B;
			if (B == 21) {
				cout << A << '-' << B << '\n';
				++setB;
				A = B = 0;
			}
		}
	}
	cout << (setA == 2?'A':'B') << '\n';

	return 0;
}