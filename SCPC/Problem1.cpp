/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case, N, K;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cin >> N >> K;
		vector<int> A;
		int in, prev=0;

		for(int i=0; i<N; i++)
		{
			cin >> in;
			A.push_back(in);
		}
		sort(A.begin(), A.end());

		Answer = 1;
		vector<int> bus (A);

		for(int i=1; i<N; i++)
		{
			int flag = 0;
			for(int j=prev+1; j<Answer; j++)
			{
				if(bus[j] + K < A[i])
				{
					bus[j] = A[i];
					prev = j;
					flag = 1;
					break;
				}
			}
			if(!flag)
			{
				for(int j=0; j<prev+1; j++)
				{
					if(bus[j] + K < A[i])
					{
						bus[j] = A[i];
						prev = j;
						break;
					}
					else if(j == prev)
					{
						bus[Answer] = A[i];
						prev = Answer;
						Answer++;
						break;
					}
				}
			}
		}
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}