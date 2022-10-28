import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, m;
        n = Integer.parseInt(in.next());
        m = Integer.parseInt(in.next());

        int[] arr = new int[n];
        BigInteger sum = BigInteger.ZERO;
        for(int i = 0; i < n; ++i) {
            arr[i] = Integer.parseInt(in.next());
            sum = sum.add(fac(arr[i]));
            // System.out.println(fac(arr[i]));
        }

        BigInteger tar = fac(m);

        // System.out.println(tar);
        // System.out.println(sum);

        BigInteger remainder = sum.mod(tar);
 

        if(remainder == BigInteger.ZERO) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        in.close();
    }

    
    static BigInteger[] dp = new BigInteger[500001];
    public static BigInteger fac(int b) {
        if(dp[b] != null) {
            return dp[b];
        }

        BigInteger res = BigInteger.ONE;
        for(int i = 1; i <= 500000; ++i) {
            res = res.multiply(BigInteger.valueOf(i));
            dp[i] = res;
        }
        return dp[b];
    }
}