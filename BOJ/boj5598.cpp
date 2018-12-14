#include <iostream>
#include <string>
using namespace std;

char decode(char e) {
	return (e - 'A' + 23) % 26 + 'A';
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	int len = str.length();
	for (int i=0; i<len; ++i) 
		str[i] = decode(str[i]);

	cout << str << '\n';
	return 0;
}