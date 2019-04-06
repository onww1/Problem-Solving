#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int input;
	while (1) {
		cin >> input;
		if (!input) break;

		if (input <= 1'000'000) {
			cout << input << '\n';
		}
		else if (input <= 5'000'000) {
			cout << (input * 90 / 100) << '\n';
		}
		else {
			cout << (input * 80 / 100) << '\n';
		}
	}
	return 0;
}