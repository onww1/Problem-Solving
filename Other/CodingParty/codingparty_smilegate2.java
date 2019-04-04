//Please don't change class name 'Main'
import java.util.Scanner;

class Main {

  public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int sum = 1;
		for(int i=0; i<n; i++)
		{
			sum += sc.nextInt() - 1;	
		}
		
		System.out.println(sum);
  }
}

