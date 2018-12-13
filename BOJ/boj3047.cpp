#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[3];
	for (int i=0; i<3; ++i) cin >> arr[i];

	sort(arr, arr+3);

	string str;
	cin >> str;

	for (int i=0; i<3; ++i) {
		cout << arr[str[i] - 'A'] << ' ';
	}
	cout << '\n';
	return 0;
}