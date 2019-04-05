#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string binary;
	cin >> binary;

	string octal = "";
	int len = binary.length();
	int o = 0;
	
	for (int i=0; i<len%3; ++i) 
		o = o * 2 + binary[i] - '0';
	
	if (o > 0) {
		octal += (char)(o + '0');
		binary = binary.substr(len%3);
		len -= len%3;
	}
	else if (len == 1) {
		octal += (char)(o + '0');
		len--;
	}

	for (int i=0; i<len; i+=3) {
		o = 0;
		for (int j=0; j<3; ++j) {
			o = o * 2 + binary[i+j] - '0';
		}
		octal += (char)(o + '0');
	}
	cout << octal << '\n';
	return 0;
}