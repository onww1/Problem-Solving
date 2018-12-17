#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int calCost(int distance) {
	if( distance < 4 || distance > 178 ) return -1;
	else if( distance <= 40 ) return 720;
	else return 720 + ((distance - 40)%8 == 0? (distance-40)/8*80 : ((distance-40)/8 + 1) * 80);
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
	
		int remain = 20000;
    for (int distance; !(ss >> distance).fail(); ) {
        // @todo Write your code here.
				int cost = calCost(distance);
				if( cost == -1 ) break;
				else if( cost > remain) break;
				else remain -= cost;
    }
    // @todo Write your code here.
		cout << remain;
    cout << endl;
    return 0;
}

