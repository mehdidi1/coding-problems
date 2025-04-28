import java.util.Scanner;
import java.util.Stack;



public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int size = sc.nextInt();
            int[] tab = new int[size];
            for (int j = 0; j < size; j++) {
                tab[j] = sc.nextInt();
            }

            Stack<Integer> temp = new Stack<>();
            temp.push(tab[0]);
            temp.push(tab[0]);
            for (int j = 1; j < size-1; j++){
                if (tab[j] > temp.peek()) {
                    temp.push(tab[j]);
                }
                else {
                    temp.push(temp.peek());
                }
            }
            long sum = 0;
            for (int j = size-1; j > -1; j--){
                sum = sum + tab[j];
                long sum2 = sum - tab[j] + temp.pop();
                System.out.print(Math.max(sum,sum2) + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}