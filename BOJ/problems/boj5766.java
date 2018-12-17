import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Boj5766{
	public static BufferedReader bf = new BufferedReader( new InputStreamReader( System.in ) );
	public static StringTokenizer st = null;

	public static void main(String[] args){
		int n, m, first, second, in;
		int[] cnt;

		try {
			while(true){
				first = second = 0;
				// input n, m
				st = new StringTokenizer( bf.readLine(), " ");
				n = Integer.parseInt( st.nextToken() );
				m = Integer.parseInt( st.nextToken() );
				if(n == 0 && m == 0) break;

				cnt = new int[10001];
				for(int i=0; i<n; i++){
					st = new StringTokenizer( bf.readLine(), " ");
					for(int j=0; j<m; j++){
						in = Integer.parseInt( st.nextToken() );
						cnt[in]++;

						if(cnt[in] > first){
							second = first;
							first = cnt[in];
						}
					}
				}

				in = -1;
				for(int i=1; i<=10000; i++){
					if(cnt[i] == second){
						if(in == -1) in = i;
						else {
							System.out.print(in + " ");
							in = i;
						}
					}
				}
				if(in != -1) System.out.println(in);
			}
		} catch(IOException e){
			e.printStackTrace();
		}
		
	}

}