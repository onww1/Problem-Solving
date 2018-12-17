#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, gcd;
	int ta, tb;
	cin >> a >> b;

	ta = a>b?a:b;
	tb = a<b?a:b;

	while(true){
		gcd = tb;
		if(ta % gcd == 0){
			break;
		}

		tb = ta % gcd;
		ta = gcd;
	}

	cout << gcd << '\n';
	cout << (a * b / gcd) << '\n';
	return 0;
}