#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout

using namespace std;

int map[100][100] = {0, };

void add(int x, int y, int w, int h) {
	for(int i=x; i<x+w; i++) {
		for(int j=y; j<y+h; j++) {
			map[i][j]++;
		}
	}
}

int main() {
    int n;
    cin >> n;
    while (n-- > 0) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        // @todo Write your code here.
				add(x, y, w, h);
    }
    // @todo Write your code here.
		int max = -1;
		for(int i=0; i<100; i++){
			for(int j=0; j<100; j++){
				if(map[i][j] > max) max = map[i][j];
			}
		}
	  cout << max;
    cout << endl;
    return 0;
}

