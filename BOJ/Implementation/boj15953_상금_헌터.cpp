#include <cstdio>
using namespace std;

int pa[6] = {1, 3, 6, 10, 15, 21};
int pb[5] = {1, 3, 7, 15, 31};
int ma[6] = {500, 300, 200, 50, 30, 10};
int mb[5] = {512, 256, 128, 64, 32};

int main(void)
{
	int t, a, b;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &a, &b);
		int money = 0;
		if(a)
		{
			for(int i=0; i<6; i++)
			{
				if(a <= pa[i])
				{
					money += ma[i];
					break;
				}
			}
		}
		if(b)
		{
			for(int i=0; i<5; i++)
			{
				if(b <= pb[i])
				{
					money += mb[i];
					break;
				}
			}
		}

		money *= 10000;
		printf("%d\n", money);
	}

	return 0;
}