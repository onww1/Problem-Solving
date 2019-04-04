/* package 구문을 넣으면 안됩니다 */
import java.util.*;
import java.io.*;

/* [Notice for Java]
 * - 기본 제공되는 뼈대 코드는 입출력의 이해를 돕기위해 제공되었습니다.
 * - 뼈대코드의 활용은 선택사항이며 코드를 직접 작성하여도 무관합니다.
 *
 * - 별도의 병렬 처리나 시스템콜, 네트워크/파일접근 등을 하지 마세요
 * - 입출력의 양이 많은 문제는 BufferedReader와 BufferedWriter를 사용하면 시간을 단축할 수 있습니다.
 * - 클래스 이름은 항상 Main이어야 합니다. 주의하세요.
 * - 모든 입력과 출력은 System.in과 System.out 스트림을 이용해야 합니다.
 */

public class codingparty_smilegate1{

    //표준입력을 수행할 Scanner를 선언한다
    public static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args)
    {   //프로그램의 시작부
			int[] player = new int[5];

			//각 플레이어의 선택 정보를 저장한다
			for(int i = 0 ; i< 5; i++){
				player[i] = scanner.nextInt();
			}

			int winner = 0; //이 변수에 승리하는 사람의 수를 저장한다.


			int[] cnt = new int[3];
			for(int i = 0; i<5; i++){
				cnt[player[i]-1]++;
			}

			if(cnt[0] == 0){
				winner = cnt[2];
			} else if(cnt[1] == 0){
				winner = cnt[0];
			} else if(cnt[2] == 0){
				winner = cnt[1];
			} else {
				winner = 0;
			}

			//정답을 출력한다
			System.out.println(winner);
    }
}
