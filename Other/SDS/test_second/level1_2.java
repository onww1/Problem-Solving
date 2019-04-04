import java.util.*;
import java.io.*;

public class level1_2 {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int t, n, m, tot;
    int[] color = new int[51];
    int[] car = new int[1000];
    boolean[] isTarget = new boolean[51];

    t = scan.nextInt();
    for (int test_case = 1; test_case <= t; ++test_case) {
      n = scan.nextInt();
      m = scan.nextInt();
      tot = 0;

      for (int i = 1; i <= m; ++i) {
        color[i] = scan.nextInt();
        if (color[i] > 0) isTarget[i] = true;
        else isTarget[i] = false;
        tot += color[i]; 
      }
      for (int i = 0; i < n; ++i) {
        car[i] = scan.nextInt();
      }

      boolean isFound = false;
      int left = 0, right = 0;
      while (right < n && left <= right) {
        if (isTarget[car[right]]) {
          if (color[car[right]] > 0) {
            --tot;
            --color[car[right]];
            ++right;
            if (tot == 0) {
              isFound = true;
              break;
            }
          } else {
            while (car[left] != car[right]) {
              ++tot;
              ++color[car[left]];
              ++left;
            }
            ++left; ++right;
          }
        } else {
          while (left < right) {
            ++tot;
            ++color[car[left]];
            ++left;
          }
          ++left; ++right;
        }
      }

      System.out.print("#" + test_case + " ");
      if (isFound) System.out.println((left + 1));
      else System.out.println(0);
    }
  }
}
