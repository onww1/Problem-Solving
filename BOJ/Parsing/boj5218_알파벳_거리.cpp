#include <iostream>
#include <string>
using namespace std;

int getDistance(char c1, char c2) {
	return (c2 - c1 + 26) % 26;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	string str1, str2;

	cin >> T;
	while (T--) {
		cin >> str1 >> str2;
		int len = str1.length();

		cout << "Distances: ";
		for (int i=0; i<len; ++i) {
			cout << getDistance(str1[i], str2[i]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}