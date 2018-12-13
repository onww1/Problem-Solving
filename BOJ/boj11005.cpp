#include <iostream>
#include <vector>
using namespace std;

char parse(int num) {
	if (num < 10) return num + '0';
	else return num - 10 + 'A';
}

int main(int argc, char const *argv[])
{
	int N, base;
	cin >> N >> base;

	vector<char> stack;
	while (N > 0) {
		stack.push_back(parse(N % base));
		N /= base;
	}

	while (!stack.empty()) {
		cout << stack.back();
		stack.pop_back();
	}
	cout << '\n';
	return 0;
}