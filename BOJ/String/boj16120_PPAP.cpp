#include <iostream>
#include <string>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	int np = 0;
	int len = str.length();
	bool isPPAP = true;

	for(int i=0; i<len && isPPAP; i++){
		if(str[i] == 'P'){
			np++;
		}
		else if(str[i] == 'A'){
			if(i == len - 1) isPPAP = false;
			else if(i < len - 1 && str[i+1] == 'A') isPPAP = false;
			else if(np < 2) isPPAP = false;
			else {
				np--;
				i++;
			}
		}
	}
	if(np != 1) isPPAP = false;

	cout << (isPPAP?"PPAP":"NP") << '\n';

	return 0;
}