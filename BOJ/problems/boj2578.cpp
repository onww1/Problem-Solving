#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int mine[5][5];
	int call[25];
	bool check[12] = {0, };
	int cnt = 0;

	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			cin >> mine[i][j];

	for(int i=0; i<25; i++)
		cin >> call[i];

	for(int i=0; i<25; i++)
	{
		bool loop = true;
		for(int j=0; loop && j<5; j++)
		{
			for(int k=0; loop && k<5; k++)
			{
				if(mine[j][k] == call[i])
				{
					mine[j][k] = 0;

					if(!check[j])
					{
						int l=0;
						for(; l<5; l++)
						{
							if(mine[j][l]) break;
						}
						if(l == 5)
						{
							cnt++;
							check[j] = true;
						}
					}
					if(!check[5+k])
					{
						int l=0;
						for(; l<5; l++)
						{
							if(mine[l][k]) break;
						}
						if(l == 5)
						{
							cnt++;
							check[5+k] = true;
						}
					}
					if(j==k && !check[10])
					{
						int l=0;
						for(; l<5; l++)
						{
							if(mine[l][l]) break;
						}
						if(l == 5)
						{
							cnt++;
							check[10] = true;
						}
					}
					if(j+k == 4 && !check[11])
					{
						int l=0;
						for(; l<5; l++)
						{
							if(mine[l][4-l]) break;
						}
						if(l == 5)
						{
							cnt++;
							check[11] = true;
						}
					}

					if(cnt >= 3) loop = false;
				}
			}
		}

		if(!loop)
		{
			cout << (i+1) << '\n';
			break;
		}
	}

	return 0;
}