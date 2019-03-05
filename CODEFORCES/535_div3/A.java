/******************************************************************************
 Codeforces Round 

*******************************************************************************/
import java.util.Scanner;

public class Main
{
	public static void main(String[] args) {
		int n, l1,r1,l2,r2;
		Scanner reader = new Scanner(System.in);
		int ans = 0, ans2 = 0;
		n = reader.nextInt();
		for(int i = 0; i < n; ++i) {
		    ans = 0; ans2 = 0;
		    l1 = reader.nextInt();
		    r1 = reader.nextInt();
		    l2 = reader.nextInt();
		    r2 = reader.nextInt();
		    if(l1 == l2) {
		        if(r1 < r2) { ans = r1; ans2 = r2; }
		        else if(r1 > r2) { ans = r1; ans2 = r2; }
		        else { ans = l1; ans2 = r2; }
		    }
		    else if(l1 > l2) {
		        ans = l1; ans2 = l2;
		    }
		    else if(l1 < l2) {
		         ans = l1; ans2 = l2;
		    }
		    System.out.print(ans+" "+ans2+"\n");
		}
	    reader.close(); 
	    
	}
}