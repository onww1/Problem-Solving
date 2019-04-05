#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt = 0;
	string input;
	for (int i=0; i<5; i++) {
		getline(cin, input);
		int len = input.length();
		for (int j=0; j<len-2; j++) {
			if (input[j] == 'F' && input[j+1] == 'B' && input[j+2] == 'I') {
				cnt++;
				cout << (i+1) << ' ';
				break;
			} 
		}
	}

	if (cnt == 0) {
		cout << "HE GOT AWAY!";
	}
	cout << '\n';
	return 0;
}