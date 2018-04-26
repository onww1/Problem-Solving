import java.util.Random;

public class rand{
	public static void main(String[] args){
		int N = 7;
		String[] group = new String[N];
		String[] random = new String[N];
		Random rand = new Random(System.currentTimeMillis());
		
		// initialize group array
		group[0]  = "김소연, 이승준";
		group[1]  = "김영민, 박재한";
		group[2]  = "김고운, 이영신, 이은빈";
		group[3]  = "오태범";
		group[4]  = "김기서, 박윤응, 이지영";
		group[5]  = "권민성, 박언주";
		group[6]  = "김우섭";

		// shuffle
		for(int i=0; i<N; i++){
			int randVal = rand.nextInt(N-i);
			random[i] = group[randVal];

			String temp = group[randVal];
			group[randVal] = group[N-1-i];
			group[N-1-i] = temp;
		}

		// print
		for(int i=0; i<N; i++){
			if(i<9)
				System.out.println(" " + (i+1) +". " + random[i]);
			else
				System.out.println((i+1) +". " + random[i]);
		}
	}
}