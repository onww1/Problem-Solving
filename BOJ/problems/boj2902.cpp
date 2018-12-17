#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string line;
	getline(cin, line);

	stringstream ss(line);
	while(true){
		string token;
		getline(ss, token, '-');

		if(token == "") break;
		cout << token[0];
	}
	cout << '\n';

	return 0;
}