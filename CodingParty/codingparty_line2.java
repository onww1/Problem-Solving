import java.io.*;
import java.util.StringTokenizer;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		int numOfFrames = 0;
		
		// canvas size
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens())
		{
			String token = st.nextToken();
			if('0' <= token.charAt(0) && token.charAt(0) <= '9')
			{
				System.out.println(token);	
			}
		}
		
		// background color
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens())
		{
			String token = st.nextToken();
			if(token.charAt(0) == '0')
			{
				System.out.println(Integer.parseInt(token.substring(2), 16));	
			}
		}
		
		// number of frames
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens())
		{
			String token = st.nextToken();
			if('0' <= token.charAt(0) && token.charAt(0) <= '9')
			{
				numOfFrames = Integer.parseInt(token);	
				System.out.println(numOfFrames);
			}
		}
		
		// skip "No.: width height alpha duration"
		br.readLine(); 
		
		// list
		for(int i=1; i<=numOfFrames; i++)
		{
			st = new StringTokenizer(br.readLine());
			String[] val = new String[4];
			
			st.nextToken();
			for(int j=0; j<4; j++)
			{
				val[j] = st.nextToken();	
			}
			
			System.out.println(val[0] + "x" + val[1] + ", " + val[3] + ", " + (val[2].equals("yes")?"1":"0"));
		}
	}
}