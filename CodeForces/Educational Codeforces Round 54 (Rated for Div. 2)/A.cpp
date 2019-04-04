#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str;

	cin >> N;
	getline(cin, str);
	getline(cin, str);

	int len = str.length();
	bool isOK = false;

	for (int i=0; i<len-1; i++) {
		if (str[i] > str[i+1]) {
			if (i == 0) {
				cout << str.substr(1) << '\n';
			}
			else {
				cout << str.substr(0, i) << str.substr(i+1, len) << '\n';
			}
			isOK = true;
			break;
		}
	}

	if (!isOK) cout << str.substr(0, len-1) << '\n';

	return 0;
}