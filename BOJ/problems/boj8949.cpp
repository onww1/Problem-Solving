#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string num1, num2;
	cin >> num1 >> num2;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int len1 = num1.length();
	int len2 = num2.length();

	int len = len1 > len2 ? len1 : len2;
	int idx = len-1;
	while (idx < len1 && idx >= len2) {
		cout << num1[idx];
		idx--;
	}
	while (idx >= len1 && idx < len2) {
		cout << num2[idx];
		idx--;
	}
	while (idx >= 0) {
		cout << (num1[idx] + num2[idx] - 2 *'0');
		idx--;
	}
	cout << '\n';
	return 0;
}