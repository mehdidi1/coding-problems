import java.util.Scanner;
 
// Constest : https://codeforces.com/contest/2104

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int min = Math.min(a, b);
            int max = Math.max(a, b);
            boolean result = ((c-(max-min)-max)%3 == 0 )&&c-(max-min)>=max ;
            if (result) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }
        sc.close();
    }
}