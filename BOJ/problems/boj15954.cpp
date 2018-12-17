#include <cstdio>
#include <cmath>
using namespace std;

int a[500];
double min = 10000.0;

double avg(int start, int end)
{
	int sum = 0;
	for(int i=start; i<=end; i++)
	{
		sum += a[i];
	}
	return (double)sum / (double)(end-start+1);
}

double variance(int start, int end)
{
	double m = avg(start, end);
	double sum = 0;
	for(int i=start; i<=end; i++)
	{
		sum += (((double)a[i] - m) * ((double)a[i] - m)); 
	}
	return sum / (double)(end - start + 1);
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(int i=k; i<=n; i++)
	{
		for(int j=0; j+i-1<n; j++)
		{
			double var = variance(j, j+i-1);
			if(var < min) min = var;
		}
	}

	printf("%.11lf\n", sqrt(min));
	return 0;
}