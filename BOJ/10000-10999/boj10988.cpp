#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin >> str;

	int len = str.length();
	int isPalindrome = 1;

	for (int i=0; i<len/2; i++) {
		if (str[i] != str[len-i-1]) 
			isPalindrome = 0;
	}

	cout << isPalindrome << '\n';

	return 0;
}