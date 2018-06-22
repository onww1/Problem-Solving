import java.util.Scanner;
import java.util.HashSet;

public class codeground4{
	static int Answer;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int n, m, u, v, w;
		for(int test_case = 0; test_case < T; test_case++){
			Answer = 0;
			n = sc.nextInt();
			m = sc.nextInt();
			int[][] graph = new int[n][n];
			for(int i=0; i<n; i++) for(int j=0; i<n; i++) graph[i][j] = Integer.MIN_VALUE;
			for(int i=0; i<m; i++){
				u = sc.nextInt();
				v = sc.nextInt();
				w = sc.nextInt();
				graph[u-1][v-1] = graph[v-1][u-1] = w;
			}
			int[] d = new int[n];
			d[0] = 0;
			for(int i=1; i<n; i++) d[i] = Integer.MIN_VALUE;
			HashSet<Integer> visited = new HashSet<Integer>(n);
			visited.add(0);
			int max = Integer.MIN_VALUE, idx=0;
			for(int i=0; i<n; i++){if(graph[0][i] != 0) d[i] = graph[0][i];}
			while(visited.size() != n){
				max = Integer.MIN_VALUE;
				for(int i=1; i<n; i++){
					if(d[i] > max && !visited.contains(i)){ max = d[i]; idx = i;}
				}
				Answer += max; visited.add(idx);
				for(int i=1; i<n; i++){
					if(!visited.contains(i) && graph[idx][i] > d[i]) d[i] = graph[idx][i];
				}
			}
			System.out.println(Answer);
		}
	}
}