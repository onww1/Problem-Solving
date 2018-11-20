#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a[26] = {0,};
	string str;

	cin >> n >> str;
	for (int i=0; i<n; i++) {
		a[str[i] - 'a']++;
	}

	int max = a[0], idx = 0;
	for (int i=1; i<26; i++) {
		if (a[i] > max) {
			idx = i;
			max = a[i];
		}
	}

	cout << (char)(idx + 'a') << ' ' << max << '\n';

	return 0;
}