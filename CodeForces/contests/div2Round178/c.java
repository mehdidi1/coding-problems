import java.util.Scanner;

public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int size = sc.nextInt();
            char[] tab = sc.next().toCharArray();
            char result = ' ';

            if (tab[size - 1] == tab[0]) {
                result = tab[0];
            } else {
                boolean allSame = true;
                for (int j = 1; j < size - 1; j++) {
                    if (tab[j] != tab[0]) {
                        allSame = false;
                        break;
                    }
                }
                if (allSame) {
                    result = tab[0];
                } else if (tab[size - 1] == 'B' && tab[0] == 'A') {
                    result = 'B';
                } else if (tab[size - 1] == 'A' && tab[0] == 'B' && tab[size - 2] == 'A') {
                    result = 'A';
                } else if (tab[size - 1] == 'A' && tab[0] == 'B' && tab[size - 2] == 'B') {
                    result = 'B';
                }
            }

            if (size == 2) {
                if (tab[size - 1] == 'B' && tab[0] == 'A')
                    result = 'A';

            }

            if (result == 'A') {
                System.out.println("Alice");
            }
            if (result == 'B') {
                System.out.println("Bob");
            }

        }
        sc.close();
    }
}