/**
 * longest common subsequence
 * @author jubaer
 */
import java.util.Scanner;


public class LCS_Recursion {
    static int lcs(char[] a, char[] b){
        int[][] lc = new int[a.length+1][b.length+1];
        
        for(int i = 0; i <= a.length; i++){
            for(int j = 0; j <= b.length; j++){
                if(i == 0 || j == 0){
                    lc[i][j] = 0;
                }
                else if(a[i-1] == b[j-1]){
                    lc[i][j] = 1 + lc[i-1][j-1];
                }
                else{
                    lc[i][j] = Math.max(lc[i-1][j], lc[i][j-1]);
                }
            }
        }
        
        return lc[a.length][b.length];
    }
    
    public static void main(String args[]){
        Scanner scan =  new Scanner(System.in);
        
        char[] str1 = scan.next().toCharArray();
        char[] str2 = scan.next().toCharArray();
        
        System.out.println(lcs(str1, str2));
    }
}
