#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int len = s1.length();
	bool compatible = true;
	for (int i=0; i<len; i+=2) {
		if (s1[i] == s2[i]) {
			compatible = false;
			break;
		}
	}

	cout << (compatible?"Y":"N") << '\n';
	return 0;
}