import java.util.Scanner;
import java.lang.Math;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        
        while (true){

        int n = in.nextInt();
        int m = in.nextInt();


        if (n ==0 && m == 0)
            break;

        int[][] input;
        int[][] dp;
        
        input = new int[n+1][m+1];
        dp = new int[n+1][m+1];
        
        for (int i = 1; i <= n ; i++)
        {
            for (int j =1; j <= m; j++)
            input[i][j] = in.nextInt();
        }
        
        int ans = 0;
        for (int i = 1; i <= n ; i++)
        {
            for (int j =1; j <= m; j++)
            {
                if (input[i][j] == 1) 
                    dp[i][j] = Math.min(dp[i-1][j], Math.min(dp[i-1][j-1], dp[i][j-1])) +1;
                ans = Math.max(ans, dp[i][j]);
            }
        }
        System.out.println(ans);
    }
    }
}