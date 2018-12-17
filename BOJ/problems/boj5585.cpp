#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, num=0;
	cin >> n;
	n = 1000 - n;

	while(n>0)
	{
		if(n>=500) n-=500;
		else if(n>=100) n-=100;
		else if(n>=50) n-=50;
		else if(n>=10) n-=10;
		else if(n>=5) n-=5;
		else n-=1;
		num++;
	}

	cout << num << '\n';
	return 0;
}