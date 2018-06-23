import java.util.Scanner;

public class Problem1
{
	static int Answer;

	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for(int test_case = 0; test_case < T; test_case++)
		{
			int N = sc.nextInt();
			int K = sc.nextInt();
			int[] A = new int[N];
			int[] bus = new int[N];

			for(int i=0; i<N; i++) 
				A[i] = sc.nextInt();

			quickSort(A, 0, N-1);

			Answer = 1;
			bus[0] = A[0];

			for(int i=1; i<N; i++)
			{
				for(int j=0; j<Answer; j++)
				{
					if(bus[j] + K < A[i])
					{
						bus[j] = A[i];
						break;
					}
					else if(j == Answer-1)
					{
						bus[Answer] = A[i];
						Answer++;
						break;
					}
				}
			}

			System.out.println("Case #" + (test_case + 1));
			System.out.println(Answer);
		}
	}

	public static void quickSort(int[] arr, int left, int right)
	{
		int pivot = left;
		int ll = left+1;
		int rr = right;

		if(left >= right) return;

		while(true)
		{
			while(arr[pivot] > arr[ll] && ll < right) ll++;
			while(arr[pivot] < arr[rr] && rr > left) rr--;

			if(ll < rr)
			{
				int temp = arr[ll];
				arr[ll] = arr[rr];
				arr[rr] = temp;
			}
			else if(ll >= rr)
			{
				int temp = arr[pivot];
				arr[pivot] = arr[rr];
				arr[rr] = temp;
				break;
			}
		}

		quickSort(arr, left, rr-1);
		quickSort(arr, rr+1, right);
	}
}