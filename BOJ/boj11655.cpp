#include <iostream>
#include <string>
using namespace std;

char parse(char c) {
	if ('A' <= c && c <= 'Z') return (c - 'A' + 13) % 26 + 'A';
	if ('a' <= c && c <= 'z') return (c - 'a' + 13) % 26 + 'a';
	return c;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	getline(cin, str);

	int len = str.length();
	for (int i=0; i<len; ++i) str[i] = parse(str[i]);
	cout << str << '\n';

	return 0;
}