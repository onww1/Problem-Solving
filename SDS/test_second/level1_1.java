import java.util.*;
import java.io.*;

public class level1_1 {

  public static int parse(char c) {
    return (int)(c - 'a');
  }
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    
    int t, n;
    char c;
    
    t = scan.nextInt();
    for (int test_case = 1; test_case <= t; ++test_case) {
      Deque<Character> dq = new LinkedList<Character>();
      n = scan.nextInt();
      c = scan.next().charAt(0);
      dq.add(c);
      for (int i=1; i<n; ++i) {
        c = scan.next().charAt(0);
        if (parse(dq.peekFirst()) <= parse(c)) {
          dq.addFirst(c);
        } else dq.addLast(c);
      }

      System.out.print("#" + test_case + " ");
      Iterator<Character> it = dq.iterator();
      while (it.hasNext()) {
        System.out.print(it.next());
      }
      System.out.println("");
    }
  }
}