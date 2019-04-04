#include <iostream>
#include <string>
using namespace std;

int parse(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	else if ('A' <= c && c <= 'Z') return c - 'A' + 10;
	else return -1;
}

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	int base;
	cin >> base;

	int len = str.length();
	int val = 0;
	for (int i=0; i<len; ++i) {
		val = val * base + parse(str[i]);
	}
	cout << val << '\n';
	return 0;
}