#include <iostream>
#include <vector>
using namespace std;

int f(int n) {
	int res = 0;
	while (n > 0) {
		int remain = n % 10;
		n /= 10;

		res += (remain * remain);
	}
	return res;
}

bool contain(vector<int>& memory, int num) {
	int len = memory.size();
	for (int i=0; i<len; i++) {
		if (memory[i] == num) return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	vector<int> memory;
	bool isHappy = false;

	while (true) {
		if (N == 1) {
			isHappy = true;
			break;
		}

		if (contain(memory, N)) {
			break;
		}
		memory.push_back(N);

		N = f(N);
	}

	cout << (isHappy?"HAPPY":"UNHAPPY") << '\n';
	return 0;
}