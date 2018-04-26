import java.util.Scanner;
import java.util.HashSet;

public class Solution{
	static long answer;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t, n, m, u, v;
		long[] d;
		int[] r;
		int[][] w;
		HashSet<Integer> visited;
		t = sc.nextInt();
		for(int test_case=0; test_case<t; test_case++){
			n = sc.nextInt();
			m = sc.nextInt();
			r = new int[n];
			d = new long[n];
			w = new int[n][n];
			visited = new HashSet<Integer>(n);
			for(int i=0; i<n; i++){
				d[i] = (long)(Integer.MAX_VALUE); 
				for(int j=0; j<n; j++) w[i][j] = Integer.MAX_VALUE;
			}
			for(int i=0; i<n; i++) r[i] = sc.nextInt();
			for(int i=0; i<m; i++){
				u = sc.nextInt();
				v = sc.nextInt();
				w[u-1][v-1] = w[v-1][u-1] = sc.nextInt();
			}
			long min;
			int idx;
			d[0] = r[0]; visited.add(0); answer = 0l;
			for(int i=1; i<n; i++) 
				if(w[0][i] != Integer.MAX_VALUE) d[i] = d[0] + w[0][i] + r[i];
			while(visited.size() != n){
				min = (long)(Integer.MAX_VALUE); idx=0;
				for(int i=1; i<n; i++)
					if(!visited.contains(i) && min > d[i]){min = d[i]; idx=i;}
				if(min == (long)(Integer.MAX_VALUE)) break;
				visited.add(idx);
				for(int i=1; i<n; i++){
					if(!visited.contains(i) && d[idx] + w[idx][i] + r[i] < d[i])
						d[i] = d[idx] + w[idx][i] + r[i];
				}
			}
			for(int i=0; i<n; i++) if(d[i] != (long)(Integer.MAX_VALUE)) answer += d[i];
			System.out.println(answer);
		}
	}
}