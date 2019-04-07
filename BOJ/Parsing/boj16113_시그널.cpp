#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int bucket[3];
vector<string> v;

int colInterpreter(int col){
	bool b[5] = {false, };
	for(int i=0; i<5; i++){
		b[i] = (v[i][col] == '#');
	}

	if(!b[0] && !b[1] && !b[2] && !b[3] && !b[4]) return 0;
	else if(b[0] && b[1] && b[2] && b[3] && b[4]) return 1;
	else if(b[0] && !b[1] && b[2] && b[3] && b[4]) return 2;
	else if(b[0] && !b[1] && b[2] && !b[3] && b[4]) return 3;
	else if(b[0] && b[1] && b[2] && !b[3] && b[4]) return 4;
	else if(b[0] && b[1] && b[2] && !b[3] && !b[4]) return 5;
	else if(!b[0] && !b[1] && b[2] && !b[3] && !b[4]) return 6;
	else if(b[0] && !b[1] && !b[2] && !b[3] && !b[4]) return 7;
	else if(b[0] && !b[1] && !b[2] && !b[3] && b[4]) return 8;
	return -1;
}

int interpret(){
	if(bucket[0] == 1 && bucket[1] == 8 && bucket[2] == 1) return 0;
	else if(bucket[0] == 1 && bucket[1] == 0 && bucket[2] == 0) return 1;
	else if(bucket[0] == 2 && bucket[1] == 3 && bucket[2] == 4) return 2;
	else if(bucket[0] == 3 && bucket[1] == 3 && bucket[2] == 1) return 3;
	else if(bucket[0] == 5 && bucket[1] == 6 && bucket[2] == 1) return 4;
	else if(bucket[0] == 4 && bucket[1] == 3 && bucket[2] == 2) return 5;
	else if(bucket[0] == 1 && bucket[1] == 3 && bucket[2] == 2) return 6;
	else if(bucket[0] == 7 && bucket[1] == 7 && bucket[2] == 1) return 7;
	else if(bucket[0] == 1 && bucket[1] == 3 && bucket[2] == 1) return 8;
	else if(bucket[0] == 4 && bucket[1] == 3 && bucket[2] == 1) return 9;
	return -1;
}


int main(){
	string str;

	cin >> N;
	cin >> str;

	int len = str.length();
	for(int i=0; i<5; i++)
		v.push_back(str.substr(N/5 * i, N/5));

	int ptr = 0;
	for(int col = 0; col < N/5; col++){
		int val = colInterpreter(col);
		if(val == 0 || col == N/5 - 1){
			if(col == N/5 - 1) bucket[ptr++] = val;

			for(; ptr < 3; ptr++) bucket[ptr] = 0;

			int res = interpret();
			if(res >= 0) cout << res;
			ptr = 0;
		}
		else{
			bucket[ptr] = val;
			ptr++;
		}
	}

	cout << '\n';
	return 0;
}