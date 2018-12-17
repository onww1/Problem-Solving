#include <iostream>
#include <string>
using namespace std;

int type(char c) {
	if ('a' <= c && c <= 'z') return 0;
	else if ('A' <= c && c <= 'Z') return 1;
	else if ('0' <= c && c <= '9') return 2;
	else if (c == ' ') return 3;
	return -1;
}

int main(int argc, char const *argv[])
{
	string str;
	while (getline(cin, str)) {
		int arr[4] = {0,};
		int len = str.length();
		if (!len) continue;
		for (int i=0; i<len; ++i) 
			arr[type(str[i])]++;
		for (int i=0; i<4; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}