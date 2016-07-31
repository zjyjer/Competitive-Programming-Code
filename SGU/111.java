import java.util.*;
import java.math.*;

public class Solution
{ 
public static void main(String[] args) {
	BigInteger a;
	BigInteger two=BigInteger.valueOf(2);
	BigInteger zero=BigInteger.ZERO;
	BigInteger l,h,mid,tmp;
	Scanner cin = new Scanner(System.in);
	a=cin.nextBigInteger();
	l=BigInteger.valueOf(1);
	h=a;
	while ((h.subtract(l)).compareTo(zero)==1)
	{
		//System.out.print(h);
		//System.out.println(l);
		mid=h.add(l);
		mid=mid.divide(two).add(BigInteger.ONE);
		tmp=mid.pow(2);
		if(a.compareTo(tmp)==-1)
			h=mid.subtract(BigInteger.ONE); 
		else l=mid;
	}
	System.out.println(l);
}
}
