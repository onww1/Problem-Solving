#include <iostream>
#include <string>
using namespace std;

int parseHexToDec(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	else if ('A' <= c && c <= 'F') return c - 'A' + 10;
	return -1;
}

int main(int argc, char const *argv[])
{
	string hex;
	cin >> hex;

	int len = hex.length();
	int dec = 0;
	for (int i=0; i<len; ++i) 
		dec = dec * 16 + parseHexToDec(hex[i]);
	cout << dec << '\n';
	return 0;
}