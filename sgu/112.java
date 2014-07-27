import java.util.*;
import java.math.*;

public class Solution
{
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		BigInteger a,b,c,d,ans;
		int m,n;
		while(cin.hasNextInt())
		{	
			m=cin.nextInt();
			n=cin.nextInt();
			a=BigInteger.valueOf(m);
			b=BigInteger.valueOf(n);
			c=a.pow(n);
			d=b.pow(m);
			ans=c.subtract(d);
			System.out.println(ans);
		}
	}
}