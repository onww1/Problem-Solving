#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, n, k, l, i, res, max;
	int s[10000], q[10000];
	int spare[4];

	cin >> t;
	for(int test_case=1; test_case<=t; test_case++)
	{
		cin >> n >> k >> l;
		for(int i=0; i<n; i++)
		{
			cin >> s[i] >> q[i];
		}
		spare[1] = spare[2] = spare[3] = 0;
		
		res = 0;
		for(i=0; i < n && l >= s[i]; i++)
		{
			res += 10;
			l -= s[i];
			spare[q[i]] += (s[i] - k);
		}

		if(i < n && l >= k)
		{
			res += 10;
			if(q[i] == 1)
			{
				res -= (s[i] - l);
				spare[1] += (l - k > 0?l-k:0);
			}
			else if(q[i] == 2)
			{
				if(spare[1] >= s[i] - l)
				{
					res -= (s[i] - l);
					spare[1] -= (s[i] - l);
					spare[2] += (s[i] - k);
				}
				else
				{
					res -= (spare[1] + (s[i] - l - spare[1]) * 2);
					spare[2] += (l+spare[1]-k);
					spare[1] = 0;
				}
			}
			else
			{
				if(spare[1] >= s[i] - l)
				{
					res -= (s[i] - l);
					spare[1] -= (s[i] - l);
					spare[3] += (s[i] - k);
				}
				else if(spare[1] + spare[2] >= s[i] - l)
				{
					res -= (spare[1] + (s[i] - l - spare[1]) * 2);
					spare[3] += (s[i] - k);
					spare[2] -= (s[i] - l - spare[1]);
					spare[1] = 0;
				}
				else
				{
					res -= (spare[1] + spare[2] * 2 + (s[i] - l - spare[1] - spare[2]) * 3);
					spare[3] += ( l + spare[1] + spare[2] - k);
					spare[2] = spare[1] = 0;
				}
			}
			l = 0;
			i++;
		}

		max = res;
		if( i<n && l>0 )
		{
			int tmp = s[i];
			tmp -= l;
			for(int j=1; j<=q[i]; j++)
			{
				if(tmp >= spare[j])
				{
					res -= (j * spare[j]);
					tmp -= spare[j];
					spare[j] = 0;
				}
				else
				{
					res -= (j * tmp);
					spare[j] -= tmp;
					tmp = 0;
					break;
				}
			}

			if(tmp > 0)
			{
				for(int j=q[i]+1; j<=3; j++)
				{
					if(tmp <= spare[j])
					{
						res -= (j * tmp);
						spare[j] -= tmp;
						tmp = 0;
						break;
					}
					else
					{
						res -= (j * spare[j]);
						tmp -= spare[j];
						spare[j] = 0;
					}
				}
			}

			spare[q[i]] += (s[i] - tmp - k>0 ? s[i]-tmp-k:0);
			if(tmp > 0)
			{
				cout << "print1\n";
				cout << "#" << test_case << " " << max << '\n';
				continue;
			}
			else max = (max > res)?max:res;
			i++;
		}

		bool flag = false;
		while(i < n && (spare[1] + spare[2] + spare[3] > s[i]))
		{
			int tmp = s[i];
			for(int j=1; j<=q[i]; j++)
			{
				if(tmp >= spare[j])
				{
					res -= (j * spare[j]);
					tmp -= spare[j];
					spare[j] = 0;
				}
				else
				{
					res -= (j * tmp);
					spare[j] -= tmp;
					tmp = 0;
					break;
				}
			}

			if(tmp > 0)
			{
				for(int j=q[i]+1; j<=3; j++)
				{
					if(tmp <= spare[j])
					{
						res -= (j * tmp);
						spare[j] -= tmp;
						tmp = 0;
						break;
					}
					else
					{
						res -= (j * spare[j]);
						tmp -= spare[j];
						spare[j] = 0;
					}
				}
			}

			spare[q[i]] += (s[i] - tmp - k>0 ? s[i]-tmp-k:0);
			if(tmp > 0)
			{
				cout << "print2\n";
				cout << "#" << test_case << " " << max << '\n';
				flag = true;
				break;
			}
			else max = (max > res)?max:res;
			i++;
		}
		if(flag) continue;

		cout << "print3\n";
		cout << i << '\n';
		cout << "#" << test_case << " " << max << '\n';
	}
	return 0;
}