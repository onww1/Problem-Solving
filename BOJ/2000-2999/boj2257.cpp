#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int OPEN = 10000;
const int CLOSE = 20000;

int parse(char c) {
	if (c == 'H') return 1;
	else if (c == 'C') return 12;
	else if (c == 'O') return 16;
	else if ('2' <= c && c <= '9') return c - '0';
	else if (c == '(') return OPEN;
	else return CLOSE;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string input;
	cin >> input;

	vector<int> stack;

	int sum = 0, elem = 0;
	int len = input.length();
	int val;

	for (int i=0; i<len; i++) {
		val = parse(input[i]);
		if (val == OPEN) {
			if (elem) sum += elem;
			stack.push_back(sum);
			sum = 0;
			elem = 0;
		}
		else if (val == CLOSE) {
			if (elem) sum += elem;
			elem = sum;
			sum = stack.back();
			stack.pop_back();
		}
		else if (2 <= val && val <= 9) {
			if (elem) elem *= val;
			sum += elem;
			elem = 0;
		}
		else {
			if (elem) sum += elem;
			elem = val;
		}
	}

	if (elem) sum += elem;

	cout << sum << '\n';

	return 0;
}