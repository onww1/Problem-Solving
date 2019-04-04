import java.util.Random;

public class decision{
	public static void main(String[] args) throws Exception{
		Random rand = new Random(System.currentTimeMillis());
		int[] num = new int[2];
		num[0] = num[1] = 0;
		for(int i=0; i<100; i++){
			num[rand.nextInt(2)]++;
		}
		if(num[0] > num[1]) System.out.println("해라 임마");
		else if(num[0] < num[1]) System.out.println("하지마라");
		else System.out.println("모르겠따..");
	}
}