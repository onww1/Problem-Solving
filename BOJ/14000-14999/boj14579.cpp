#include <iostream>
#define MOD 14579
using namespace std;

int calc(int n) {
	return n * (n + 1) / 2;
}

int main(int argc, char const *argv[])
{
	int a, b, res = 1;
	cin >> a >> b;

	for (int i=a; i<=b; i++) {
		res = ( res * calc(i) ) % MOD;
	}	

	cout << res << '\n';
	
	return 0;
}