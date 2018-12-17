#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

bool isPalindrome(string str) {
	int len = str.length();
	bool ok = true;
	for (int i=0; i<len/2; ++i) {
		if (str[i] != str[len - 1 - i]) {
			ok = false;
			break;
		}		
	}
	return ok;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	int cnt[26];
	string str;
	while (T--) {
		cin >> str;
		if (!isPalindrome(str)) {
			cout << str << '\n';
			continue;
		}

		memset(cnt, 0, sizeof(int) * 26);
		int len = str.length();
		for (int i=0; i<len; ++i) {
			cnt[str[i] - 'a']++;
		}

		bool isImpossible = false;
		for (int i=0; i<26; ++i) {
			if (cnt[i] == len) isImpossible = true;
		}

		if (isImpossible) cout << -1 << '\n';
		else {
			bool isSwapped = false;
			for (int i=0; !isSwapped && i<len/2; ++i) {
				for (int j=i+1; !isSwapped && j<len/2; ++j) {
					if (str[i] != str[j]) {
						swap(str[i], str[j]);
						isSwapped = true;
					}
				}
			}
			if (isSwapped) cout << str << '\n';
			else {
				swap(str[len/2], str[len/2-1]);
				cout << str << '\n';
			}
		}
	}

	return 0;
}