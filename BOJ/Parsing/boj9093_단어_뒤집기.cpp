#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isLetter(char c) {
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int N;
	string str;

	cin >> N;
	getline(cin, str);
	for (int i=0; i<N; i++) {
		getline(cin, str);
		int left = 0, right = 0;
		bool flag = false;
		int len = str.length();
		for (int j=0; j<len; j++) {
			if (!flag && isLetter(str[j])) {
				left = j;
				flag = true;
			}
			else if (flag && !isLetter(str[j])) {
				right = j;
				flag = false;
				reverse(str.begin()+left, str.begin()+right);
			}
			else if (flag && j == len-1) {
				right = len;
				flag = false;
				reverse(str.begin()+left, str.begin()+right);
			}
		}
		cout << str << '\n';
	}
	return 0;
}