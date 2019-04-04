import java.util.Scanner;
import java.util.Vector;

public class BOJ5397{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.nextLine();
		String input;
		for(int i=0; i<n; i++){
			input = sc.nextLine();
			int ptr = 0;
			Vector<Character> password = new Vector<Character>();
			for(int j=0; j<input.length(); j++){
				if(input.charAt(j) == '<'){
					if(ptr > 0) ptr--;
				}
				else if(input.charAt(j) == '>'){
					if(ptr < password.size()) ptr++;
				}
				else if(input.charAt(j) == '-'){
					if(ptr > 0){
						ptr--;
						password.removeElementAt(ptr);
					}
				}
				else{
					password.add(ptr, input.charAt(j));
				}
			}
			System.out.println(password.toString());
		}
	}
}