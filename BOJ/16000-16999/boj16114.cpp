#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int X, N;
	cin >> X >> N;

	if(N == 1){
		X *= -1;
		N--;
	}
	
	if(N%2 == 1) 
		cout << "ERROR\n";
	else {
		int interval = N/2;
		if(X <= interval) 
			cout << "0\n";
		else if(N == 0)
			cout << "INFINITE\n";
		else {
			if(X%interval == 0) cout << (X/interval - 1) << '\n';
			else cout << (X/interval) << '\n';
		}
	}

	return 0;
}