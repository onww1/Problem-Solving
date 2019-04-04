#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	int arr[10] = {0, };
	while (N>0) {
		arr[N%10]++;
		N/=10;
	}

	bool isAssociated = true;
	for (int i=0; i<10; i++) {
		if (arr[i] && i != 0 && i != 1 && i != 2 && i != 8) 
			isAssociated = false;
	}

	if (!isAssociated) cout << 0 << '\n';
	else {
		if (!arr[0] || !arr[1] || !arr[2] || !arr[8]) cout << 1 << '\n';
		else if (arr[0] == arr[1] && arr[0] == arr[2] && arr[0] == arr[8]) cout << 8 << '\n';
		else cout << 2 << '\n';
	}
	return 0;
}