import java.util.Scanner;


public class Fibonacci {
    static long fibonacci(int n){
        long[] fib = new long[n];
        fib[0] = fib[1] = 1;
        
        for(int i = 2; i < n; i++){
            fib[i] = fib[i-1]+fib[i-2];
        }
        
        return fib[n-1];
    }
    
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        System.out.println(fibonacci(scan.nextInt()));
    }
}
