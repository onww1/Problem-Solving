#include <iostream>
#include <vector>
#include <string>
using namespace std;

int parse(char c) {
	if (c == '`' || c == '1' || c =='Q' || c =='A' || c == 'Z') return 0;
	else if (c == '2' || c == 'W' || c =='S' || c =='X') return 1;
	else if (c == '3' || c == 'E' || c =='D' || c =='C') return 2;
	else if (c == '8' || c == 'I' || c =='K' || c ==',') return 5;
	else if (c == '9' || c == 'O' || c =='L' || c =='.') return 6;
	else if (c == '4' || c == 'R' || c =='F' || c =='V' ||
			 c == '5' || c == 'T' || c =='G' || c =='B') return 3;
	else if (c == '6' || c == 'Y' || c =='H' || c =='N' ||
			 c == '7' || c == 'U' || c =='J' || c =='M') return 4;
	else return 7;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	vector<int> vec(8);

	cin >> str;
	int len = str.length();

	for (int i=0; i<len; ++i) 
		vec[parse(str[i])]++;

	for (int i=0; i<8; ++i)
		cout << vec[i] << '\n';

	return 0;
}