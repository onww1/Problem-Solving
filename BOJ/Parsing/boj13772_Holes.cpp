#include <iostream>
#include <string>
using namespace std;

int hole(char c) {
	if (c == 'Q' || c == 'R' || c == 'O' || c == 'P' ||
		c == 'A' || c == 'D') return 1;
	else if (c == 'B') return 2;
	else return 0;
}

int count(string& str) {
	int len = str.length();
	int sum = 0;
	for (int i=0; i<len; i++) {
		sum += hole(str[i]);
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string str;

	cin >> n;
	getline(cin, str);
	for (int i=0; i<n; i++) {
		getline(cin, str);
		cout << count(str) << '\n';
	}
	return 0;
}