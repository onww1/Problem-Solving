#include <cstdio>
#include <cstring>

char original[1001] = {0, }, removeArr[1001] = {0, } , result[1001] = {0, };
int originalCnt[10] = {0, }, removeCnt[10] = {0, };

bool check( int idx, int len )
{
	bool res = true;
	char c = original[idx];
	int val = original[idx] - '0';

	if( !removeCnt[val] ) res = false;
	else if( originalCnt[val] == removeCnt[val] ) res = true;
	else
	{
		for(int i=idx+1; i<len; i++)
		{
			if(original[i] < c)
			{
				if(originalCnt[original[i] - '0'] > 0 && removeCnt[original[i] - '0'] == 0)
				{
					res = false;
					break;
				}
			}
			else if(original[i] == c)
			{
				res = false;
				break;
			}
			else if(original[i] > c)
			{
				if(originalCnt[original[i] - '0'] == removeCnt[original[i] - '0'])
				{
					continue;
				}
				else
				{
					res = true;
					break;
				}
			}
		}
	}

	//printf("%d\n", res);
	return res;
}

int main(int argc, char const *argv[])
{
	scanf("%s", original);
	scanf("%s", removeArr);

	int originalLen = strlen(original);
	int removeLen = strlen(removeArr);

	for(int i=0; i<originalLen; i++)
	{
		originalCnt[original[i]-'0']++;
	}
	for(int i=0; i<removeLen; i++)
	{
		removeCnt[removeArr[i]-'0']++;
	}

	int cnt=0, val=0;
	for(int i=0; i<originalLen; i++)
	{
		val = original[i] - '0';
		//printf("%d\n", val);
		if( check(i, originalLen) )
		{
			originalCnt[val]--;
			removeCnt[val]--;
		}
		else
		{
			originalCnt[val]--;
			result[cnt++] = original[i];
		}
	}

	result[cnt] = '\0';
	printf("%s\n", result);

	return 0;
}

