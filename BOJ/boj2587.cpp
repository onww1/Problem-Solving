#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int A[5], sum=0;
	for (int i=0; i<5; ++i) {
		cin >> A[i];
		sum += A[i];
	}

	sort(A, A+5);

	cout << (sum / 5) << '\n' << A[2] << '\n';

	return 0;
}