#include <iostream>
using namespace std;

int main(){
		int n;
		cin >> n;

		if(n%2 == 0) cout << "I LOVE CBNU" << '\n';
		else
		{
			for(int i=0; i<n; i++) cout << '*';
			cout << '\n';

			for(int i=n/2; i>=0; i--)
			{
				int j = 0;
				for(; j<i; j++) cout << ' ';
				cout << '*';
				for(int k=0; k< 2 * (n/2 - i) - 1; k++) cout << ' ';
				if(i==n/2) cout << '\n';
				else cout << "*\n";
			}
		}

		return 0;
}
