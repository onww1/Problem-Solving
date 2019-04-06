#include <iostream>
#include <string>
using namespace std;

int solve(string str) {
	int sum = 0, num = 0;
	int len = str.length();
	for (int i=0; i<len; ++i) {
		if ('0' <= str[i] && str[i] <= '9') {
			num = num * 10 + str[i] - '0';
			if (i == len - 1) sum += num;
		}
		else {
			sum += num;
			num = 0;
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;
	cout << solve(str) << '\n';
	return 0;
}