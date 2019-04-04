#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int nextIndice[1001] = { 0, };
int indegree[1001] = { 0, };

int main() {
    int n;
    cin >> n;
    string line;
    getline(cin, line);  // drop a newline traling n
	
	bool valid = true;
    while (n-- > 0 && valid) {
		getline(cin, line);
        stringstream ss(line);
    	int prev = -1;
        for (int fork; !(ss >> fork).fail(); ) {  // read forks from a note
            // @todo Write your code here.
			if( prev == -1 ) {
				prev = fork;
				continue;
			}
		
			if( nextIndice[prev] != 0 && nextIndice[prev] != fork) {
				valid = false;
				break;
			}
		
			if( nextIndice[prev] == 0 )
				indegree[fork]++;
		
			nextIndice[prev] = fork;
			prev = fork;
        }
        // @todo Write your code here.
    }
    // @todo Write your code here.
	if(!valid) cout << "-1" << '\n';
	else {
		for(int i=1; i<=1000; i++){
			if( indegree[i] > 0 && nextIndice[i] == 0 ) cout << i << ' ';
		}
		cout << '\n';
	}
	
    return 0;
}

