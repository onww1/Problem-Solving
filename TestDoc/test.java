import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n;
		String[] split;

		n = sc.nextInt();
		sc.nextLine();
		for(int i=1; i<=n; i++){
			split = sc.nextLine().split(" ");
			for(int j=0; j<split.length/2; j++){
				String temp = split[j];
				split[j] = split[split.length-1-j];
				split[split.length-1-j] = temp;
			}
			System.out.print("Case #" + i + ": ");
			for(int j=0; j<split.length; j++){
				System.out.print(split[j]);
				if(j != split.length-1)
					System.out.print(" ");
				else System.out.println("");
			}
		}
	}
}