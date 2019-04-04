#include <iostream>
#include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <string>
using namespace std;

int map[20][20] = {0, };
int image[20][20] = {0, };
int lx, ly, rx, ry;
int imageSize;

int main() {
    int width, height, rotation, magnification, shift_x, shift_y;
    cin >> width >> height >> rotation >> magnification >> shift_x >> shift_y;
   	
   	string line;
   	getline(cin, line);
  
   	for(int row = 0; row < height; row++) {
   		getline(cin,line);
   		for(int i=0; i<len; i+=2) {
   			image[row][i/2] = line[i] -'0';
   		}
   	}

   	for(int i=0; i<imageSize; i++){
   		for(int j=0; j<imageSize; j++) {
   			cout << image[i][j];
   		}
   		cout << '\n';
   	}

   	ly = lx = 10 - imageSize/2;
   	ry = rx = 10 + imageSize/2;

   	lx = ly = (ly - 10) * magnification + 10;
   	ry = rx = (ry - 10) * magnification + 10;

   	lx += shift_x;
   	rx += shift_x;
   	ly += shift_y;
   	ry += shift_y;


    return 0;
}