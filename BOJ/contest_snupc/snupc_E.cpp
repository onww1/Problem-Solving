#include <iostream>
#include <string>
using namespace std;

int parse(char c){
	if(c == 'B') return 0;
	else if(c == 'G') return 1;
	else if(c == 'O') return 2;
	else if(c == 'R') return 3;
	else if(c == 'W') return 4;
	else if(c == 'Y') return 5;
	return -1;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string b[8];
	for(int i=0; i<8; i++)
		cin >> b[i];



	return 0;
}