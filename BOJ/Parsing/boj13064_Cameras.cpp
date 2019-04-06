#include <iostream>
#include <string>
using namespace std;

bool isUpperAlphabet(char c) {
	if ('A' <= c && c <= 'Z') return true;
	else return false;
}

bool isDigit(char c) {
	if ('1' <= c && c <= '9') return true;
	else return false;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string input;
	while (N--) {
		cin >> input;
		bool isOK = true;
		if (!isDigit(input[0]) || input[0] != input[1]) isOK = false;
		if (!isDigit(input[2]) || !isDigit(input[3])) isOK = false;
		if (!isUpperAlphabet(input[4])) isOK = false;
		if (!isDigit(input[5]) || !isDigit(input[6]) || !isDigit(input[7])) isOK = false;
		if (isOK) cout << input << '\n'; 
	}
	return 0;
}