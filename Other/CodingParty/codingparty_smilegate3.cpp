#include <iostream>

using namespace std;

int main() {
	int srcX, srcY, srcR;
	int x[5], y[5];
	
	cin >> srcX >> srcY >> srcR;
	for(int i=0; i<5; i++)
	{
		cin >> x[i] >> y[i];	
	}
	
	srcR *= srcR;
	for(int i=0; i<5; i++)
	{
		x[i] = (x[i] - srcX) * (x[i] - srcX);
		y[i] = (y[i] - srcY) * (y[i] - srcY) + x[i];
	}
	
	int idx = -1;
	int min = 1e9 + 7;
	for(int i=0; i<5; i++)
	{
		if(srcR >= y[i])
			if(y[i] < min)
			{
				min = y[i];
				idx = i;
			}
	}
	
	if(idx == -1) cout << idx << '\n';
	else cout << idx + 1 << '\n';
	
  return 0;
}