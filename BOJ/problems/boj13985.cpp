#include <iostream>
#include <string>
using namespace std;

int parse(char c) {
	return c - '0';
}

int main(int argc, char const *argv[])
{
	string str;
	getline(cin, str);

	if (parse(str[0]) + parse(str[4]) == parse(str[8]))
		cout << "YES" << '\n';
	else 
		cout << "NO" << '\n';
	return 0;
}